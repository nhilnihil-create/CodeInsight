#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	string S;
	cin >> S;
	int year = 0, month = 0, day = 0;
	for (int i = 0; i < 4; i++) {
		year += (S[i] - '0') * pow(10, 3 - i);
	}
	for (int i = 5; i < 7; i++) {
		month += (S[i] - '0') * pow(10, 6 - i);
	}
	string ans = "TBD";
	if (year < 2019) ans = "Heisei";
	else if (year == 2019) {
		if (month <= 4) ans = "Heisei";
	}
	cout << ans << endl;
	return 0;
}