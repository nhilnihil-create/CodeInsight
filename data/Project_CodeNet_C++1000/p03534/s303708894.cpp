#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
string s; int ca, cb, cc;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a') ca++;
		if (s[i] == 'b') cb++;
		if (s[i] == 'c') cc++;
	}
	int quot = s.size() / 3;
	if ((ca == quot || ca == quot + 1) && (cb == quot || cb == quot + 1) && (cc == quot || cc == quot + 1)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}