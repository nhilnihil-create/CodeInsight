#include <iostream>
#include <vector>
#include <string>
#include <valarray>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int x = 0, ans = INT_MAX;
	const int z = 753;
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 2; i++) {
		x = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
		ans = min(ans, abs(z - x));
	}
	cout << ans << endl;
}