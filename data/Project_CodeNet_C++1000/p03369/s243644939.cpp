#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	string s;
	cin >> s;
	int t = 0;
	if (s[0] == 'o') t += 100;
	if (s[1] == 'o') t += 100;
	if (s[2] == 'o') t += 100;
	cout << 700 + t << endl;
	return 0;
}