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
	string ans;
	int num0 = S[0] - '0';
	int num1 = S[1] - '0';
	int num2 = S[2] - '0';
	int num3 = S[3] - '0';
	int classify = 0;
	if (num0 == 0 && num1 > 0) classify += 2;
	else if (num0 == 1) {
		if (num1 <= 2) classify += 2;
	}
	if (num2 == 0 && num3 > 0) classify += 1;
	else if (num2 == 1) {
		if (num3 <= 2) classify += 1;
	}

	if (classify == 0) ans = "NA";
	else if (classify == 1) ans = "YYMM";
	else if (classify == 2) ans = "MMYY";
	else if (classify == 3) ans = "AMBIGUOUS";
	cout << ans << endl;

	return 0;
}