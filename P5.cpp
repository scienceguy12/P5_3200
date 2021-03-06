#include "stdafx.h"

#include "imageCollage.h"
#include "cyclicCollage.h"
#include "bitCollage.h"
#include <iostream>

void displayCollage(vector<int> imgCol);
imageCollage operator+(int addID, imageCollage& imgCol);
cyclicCollage operator+(int addID, cyclicCollage& imgCol);
bitCollage operator+(int addID, bitCollage& imgCol);

int main()
{
	const int NO_ERRORS = 0;

	cout << "Testing overloaded operator+ with two imageCollage objects: " << endl;

	vector<int> testDisplay1 = { 1, 2, 3, 4 };
	vector<int> testDisplay2 = { 5, 6, 7, 8 };

	imageCollage testCollage1(testDisplay1);
	imageCollage testCollage2(testDisplay2);
	
	imageCollage sumCollage = testCollage1 + testCollage2;
	imageCollage sumCollage2 = testCollage2 + testCollage1;

	displayCollage(sumCollage.getDisplay());

	cout << endl << endl;

	displayCollage(sumCollage2.getDisplay());

	imageCollage testCollage3(testDisplay1);
	int testInt = 9;
	imageCollage intCollage = testCollage3 + testInt;

	cout << endl << endl;

	displayCollage(intCollage.getDisplay());

	imageCollage intCollage2 = testInt + testCollage3;

	cout << endl << endl;

	displayCollage(intCollage2.getDisplay());

	cout << endl << endl;

	vector<int> testDisplay3 = { 9, 9, 9, 9 };
	imageCollage testCollage4(testDisplay3);

	testCollage1 += testCollage4;

	displayCollage(testCollage1.getDisplay());

	//Cyclic
	cout << endl << "CYCLIC:";
	cout << endl << endl;

	cyclicCollage testCyclic1(testDisplay1);
	cyclicCollage testCyclic2(testDisplay2);

	cyclicCollage sumCyclic = testCyclic1 + testCyclic2;
	cyclicCollage sumCyclic2 = testCyclic2 + testCyclic1;

	displayCollage(sumCyclic.getOriDisplay());

	cout << endl << endl;

	displayCollage(sumCyclic2.getOriDisplay());

	cout << endl << endl;

	cyclicCollage testCyclic3(testDisplay1);
	cyclicCollage intCyclic = testCyclic3 + testInt;

	cout << endl << endl;

	displayCollage(intCyclic.getOriDisplay());

	cyclicCollage intCyclic2 = testInt + testCyclic3;

	cout << endl << endl;

	displayCollage(intCyclic2.getOriDisplay());

	cout << endl << endl;

	cyclicCollage testCyclic4(testDisplay3);

	testCyclic1 += testCyclic4;

	displayCollage(testCyclic1.getOriDisplay());

	//Bit
	cout << endl << "BIT:";
	cout << endl << endl;

	bitCollage testBit1(testDisplay1);
	bitCollage testBit2(testDisplay2);

	bitCollage sumBit = testBit1 + testBit2;
	bitCollage sumBit2 = testBit2 + testBit1;

	displayCollage(sumBit.getFullDisplay());

	cout << endl << endl;

	displayCollage(sumBit2.getFullDisplay());

	cout << endl << endl;

	bitCollage testBit3(testDisplay1);
	bitCollage intBit = testBit3 + testInt;

	cout << endl << endl;

	displayCollage(intBit.getFullDisplay());

	bitCollage intBit2 = testInt + testBit3;

	cout << endl << endl;

	displayCollage(intBit2.getFullDisplay());

	cout << endl << endl;

	bitCollage testBit4(testDisplay3);

	testBit1 += testBit4;

	displayCollage(testBit1.getFullDisplay());

	//Mixed Mode
	cout << endl << "MIXED MODE: ";

	//cyclicCollage testCyclic5 = testCollage1 + testCyclic2;
	cyclicCollage testCyclic6 = testCyclic2 + testCollage1;

	//cout << endl << endl;

	//displayCollage(testCyclic5.getOriDisplay());

	cout << endl << endl;

	displayCollage(testCyclic6.getOriDisplay());

	bitCollage testBit6 = testBit2 + testCollage1;

	cout << endl << endl;

	displayCollage(testBit6.getFullDisplay());

	cin.get();

	return NO_ERRORS;
}

//Description - Used as a helper method to display a collage
//preconditions: Must be passed a valid vector
void displayCollage(vector<int> imgCol)
{
	if (imgCol.size() == 0)
	{
		cout << "Nothing to display.";
	}

	else
	{
		int index = 0;
		cout << imgCol[index];
		for (unsigned index = 0; index < imgCol.size(); index++)
		{
			if (index != 0)
			{
				cout << ", ";
				cout << imgCol[index];
			}
		}
	}
}

imageCollage operator+(int addID, imageCollage& imgCol)
{
	vector<int> intElement = { addID };
	imageCollage newCol(intElement);
	imageCollage sumCol = newCol + imgCol;
	return sumCol;
}

cyclicCollage operator+(int addID, cyclicCollage& imgCol)
{
	vector<int> intElement = { addID };
	cyclicCollage newCol(intElement);
	cyclicCollage sumCol = newCol + imgCol;
	return sumCol;
}

bitCollage operator+(int addID, bitCollage& imgCol)
{
	vector<int> intElement = { addID };
	bitCollage newCol(intElement);
	bitCollage sumCol = newCol + imgCol;
	return sumCol;
}