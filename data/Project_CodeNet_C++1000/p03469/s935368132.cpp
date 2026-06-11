#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ordor;

	cin >> ordor;

	ordor[0] = '2';
	ordor[1] = '0';
	ordor[2] = '1';
	ordor[3] = '8';

	cout << ordor;

	return 0;
}