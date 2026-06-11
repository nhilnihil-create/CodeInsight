#include <iostream>
using namespace std;

int val;
bool validmonth1;
bool validmonth2;

int main() {
	cin >> val;
	if (val % 100 == 0 || val % 100 > 12) {
		validmonth2 = false;
	}
	else {
		validmonth2 = true;
	}
	if ((val - (val % 100))/100 == 0 || (val - (val % 100))/100 > 12) {
		validmonth1 = false;
	}
	else {
		validmonth1 = true;
	}

	if (validmonth1 == true && validmonth2 == true) {
		cout << "AMBIGUOUS";
	}
	else if (validmonth1 == false && validmonth2 == false) {
		cout << "NA";
	}
	else if (validmonth1 == true && validmonth2 == false) {
		cout << "MMYY";
	}
	else if (validmonth1 == false && validmonth2 == true) {
		cout << "YYMM";
	}
}
