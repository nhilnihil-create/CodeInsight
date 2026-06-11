#include <iostream>

using namespace std;

int main() {

	string str;
	cin >> str;
	int charge = 700;

	if (str.at(0) == 'o') charge += 100;
	if (str.at(1) == 'o') charge += 100;
	if (str.at(2) == 'o') charge += 100;

	cout << charge << endl;
	return 0;
}