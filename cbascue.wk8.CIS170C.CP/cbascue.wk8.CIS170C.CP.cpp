// ---------------------------------------------------------------
// Programming Assignment:Course Project Wk. 8
// Developer:Codie Bascue
// Date Written:4/23/20
// Purpose:	Creating course project (final).
// ---------------------------------------------------------------

//Start with preprocessor directives/header files
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
double manPchoice(double total);
double sizeChoice(double total);
double wireChoice(double total);

int main()
{
	ofstream outfile;
	outfile.open("totals.txt");

	double total = 0.00;
	//Set the furthest decimal point available to 2
	cout << setprecision(2) << fixed << showpoint;
	//Set variable
	string menuInp;

	cout << "Welcome to the Electrician Calculator Program! \n";
	//Tell the user what the program will do
	cout << "This program will take information entered about an electrician job and calculate the total cost of the job." << endl;
	cout << endl;

	//explain the program and what it will do and how the user will operate it
	cout << "In this program, you will be choose which part of the job you would like to add to the total cost, whether that is length, size, wire length, type of wire, or anything else. \n";
	cout << "After you enter a part of the job, the program will give you a total cost at that time, and then ask if you would like to add more. \n";
	cout << "Please note that the program will not ouput a total job cost until you have entered at least one of each (length of job, size of job, length anf type of wire.) \n";
	cout << "Throughout this process, the data will be saved to a text file named 'totals' and you can view what you have put into this file at any time\n";
	cout << endl;

	ifstream infile;

	while (true)
	{

		//ask the user what they would like to input into the program first.
		cout << "What would you like to enter into the program? \n";
		cout << "A. Length of job/ number of electricians needed \n";
		cout << "B. Size of job \n";
		cout << "C. Type and length of wire needed \n";
		cout << "D. Get total cost of job currently\n";
		cout << "E. Show all costs input so far in the file\n";
		cout << "F. Exit Program";
		cout << endl;
		cin >> menuInp;
		cout << endl;

		if (menuInp == "A" || menuInp == "a")
		{
			double previousTotal = total;
			total = manPchoice(total);

			if (!outfile.is_open())
			{
				outfile.open("totals.txt", ios_base::app);
			}

			double manPcost = total - previousTotal;
			outfile << "Man Power: $" << total << "-";
		}
		else if (menuInp == "B" || menuInp == "b")
		{
			double previousTotal = total;
			total = sizeChoice(total);

			if (!outfile.is_open())
			{
				outfile.open("totals.txt", ios_base::app);
			}

			double sizeCost = total - previousTotal;
			outfile << "Size: $" << sizeCost << "-";
		}
		else if (menuInp == "C" || menuInp == "c")
		{
			double previousTotal = total;
			total = wireChoice(total);

			if (!outfile.is_open())
			{
				outfile.open("totals.txt", ios_base::app);
			}

			double wireCost = total - previousTotal;
			outfile << "Wire: $" << wireCost << "-";
		}
		else if (menuInp == "D" || menuInp == "d")
		{
			cout << "Total job cost so far is $" << total << endl;
			cout << endl;

			if (!outfile.is_open())
			{
				outfile.open("totals.txt", ios_base::app);
			}

			outfile << "Total Cost: $" << total << "-";
		}
		else if (menuInp == "E" || menuInp == "e")
		{
			outfile.close();
			infile.open("totals.txt");

			string fieldBuffer;

			if (infile.is_open())
			{
				while (!infile.eof())
				{
					getline(infile, fieldBuffer, '-');
					cout << fieldBuffer << endl;
				}
			}

			infile.close();
		}
		else if (menuInp == "F" || menuInp == "f")
		{
			break;
		}
		else
		{
			cout << "Please enter a valid input!" << endl;
		}
	}
	if (outfile.is_open())
	{
		outfile.close();
	}



	//Thank the user for using the program and say goodbye!
	cout << "Thank you for using the Electrician Calculator Program!" << endl;
	cout << endl;

	cout << "Goodbye!" << endl;
	//pause the system
	system("pause");
	return(0);

}

//create portion of program for each answer on entry
double manPchoice(double total)
{
	double manpCostRes = 00.00, elecCostHour = 17.86, jobLength;
	int numElec;

	//get number of electrictians needed for the job
	cout << "How many electrictians are needed for this job? ";
	cin >> numElec;
	cout << endl;

	cout << "Please enter the length of this job (hours): ";
	cin >> jobLength;

	//calculate total cost for manpower for this job
	manpCostRes = elecCostHour * jobLength * numElec;

	//output results of total manpower cost
	cout << "Total cost for manpower for this job is $" << manpCostRes << endl;
	cout << endl;

	return (total + manpCostRes);
}

double sizeChoice(double total)
{
	double sizeCostRes = 0.00, jobSize, jobCostSqFt = 2.55;

	//get input from user for square feet of the job
	cout << "Please enter total size of this job in square feet: ";
	cin >> jobSize;
	cout << endl;

	//calculate cost of job based on size of job
	sizeCostRes = jobCostSqFt * jobSize;

	//output to user the total extra cost estimate based on job size
	cout << "Total general cost for job based on job size (SqFt.) is $" << sizeCostRes << endl;
	cout << endl;

	return total + sizeCostRes;
}

double wireChoice(double total)
{
	double wireCostRes = 0.00, copWireLength, alumWireLength, alumCopWireLength, copWirePr = 0.99, alumWirePr = 0.20, alumCopWirePr = 1.19;
	string wireInp;
	const int NUM_TYPES = 3;
	const int coppIndex = 0;
	const int alumIndex = 1;
	const int mixIndex = 2;
	int i;
	double wireLengths[NUM_TYPES] = { 0.00, 0.00 };


	//ask user which type of wire will be used for the project
	while (wireInp != "D" && wireInp != "d")
	{
		cout << "Which type of wire will be used for this project? \n";
		cout << "A. Copper   \n";
		cout << "B. Aluminum \n";
		cout << "C. Aluminum Armored Copper \n";
		cout << "D. Back to main menu";
		cout << endl;
		cin >> wireInp;
		cout << endl;


		//Set rules for each answer
		if (wireInp == "A" || wireInp == "a")
		{
			cout << "Please enter the length of copper wire needed for this project (ft): ";
			cin >> copWireLength;
			wireLengths[coppIndex] = copWireLength;
			//Create the calculation for the total cost of copper wire and apply it to copCostRes
			wireCostRes = copWireLength * copWirePr;
			//Output to the user the total cost of copper wire for the project so far.
			cout << "The total cost for the copper wire for this project is $" << wireCostRes << endl;
			cout << endl;
		}
		else if (wireInp == "B" || wireInp == "b")
		{
			cout << "Please enter the length of aluminum wire needed for this project (ft): ";
			cin >> alumWireLength;
			wireLengths[alumIndex] = alumWireLength;
			//create calc for the total cost of aluminum wire and apply it to alumCostRes
			wireCostRes = alumWireLength * alumWirePr;
			//Output to the user the total cost of aluminum wire for this project so far
			cout << "The total cost for the aluminum wire for this project is $" << wireCostRes << endl;
			cout << endl;
		}
		else if (wireInp == "C" || wireInp == "c")
		{
			cout << "Please enter the length of aluminum armored copper wire needed for this project (ft): ";
			cin >> alumCopWireLength;
			wireLengths[mixIndex] = alumCopWireLength;
			wireCostRes = alumCopWireLength * alumCopWirePr;
			cout << "The total cost for the aluminum armored copper wire for this project is $" << wireCostRes << endl;
			cout << endl;
		}
		else if (wireInp == "D" || wireInp == "d")
		{
			break;
		}
		else
		{
			cout << "Please enter a valid input!" << endl;
			cout << endl;
		}
		cout << "Wires lengths entered so far are: " << endl;
		for (int i = 0; i < NUM_TYPES; i++)
		{
			if (i == coppIndex) {
				cout << "Copper: " << wireLengths[i] << endl;

			}
			else {
				cout << "Aluminum: " << wireLengths[i] << endl;

			}
		}
		cout << endl;
	}
	return total + wireCostRes;
}
