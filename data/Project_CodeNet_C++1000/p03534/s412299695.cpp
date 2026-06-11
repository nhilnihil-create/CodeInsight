#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int main() {
	string s;
	cin >> s;
	long long int n = s.size(), a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a')a++;
		if (s[i] == 'b')b++;
		if (s[i] == 'c')c++;
	}
	if (n % 3 == 0) {
		if (a == b&&a == c) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	if (n % 3 == 1) {
		if ((a == b&&a == c - 1) || (a == c&&a == b - 1) || (c == b&&c == a - 1)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	if (n % 3 == 2) {
		if ((a == b&&a == c + 1) || (a == c&&a == b + 1) || (c == b&&c == a + 1)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}