#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int year = stoi(s.substr(0,4));
	int month = stoi(s.substr(5,2));
	int day = stoi(s.substr(8,2));

	string ans = "Heisei";
	if (year == 2019) {
		if (4 < month) {
			ans = "TBD";
		}
	} else if (2019 < year) {
		ans = "TDB";
	}

	cout << ans << endl;
	return 0;
}
