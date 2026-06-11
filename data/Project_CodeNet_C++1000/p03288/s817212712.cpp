#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int R;
	cin >> R;
	string ans;
	if (R < 1200) ans = "ABC";
	else if (R < 2800) ans = "ARC";
	else ans = "AGC";
	cout << ans << endl;
	return 0;
}