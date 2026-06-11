#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ordor;
	int countnum = 0;

	cin >> ordor;

	if (ordor[0] == 'o') countnum++;
	if (ordor[1] == 'o') countnum++;
	if (ordor[2] == 'o') countnum++;

	cout << 100 * countnum + 700;

	return 0;
}