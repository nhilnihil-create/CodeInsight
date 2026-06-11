#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	int a, b, c;
	a = b = c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a') {
			a++;
		}
		else if (s[i] == 'b') {
			b++;
		}
		else {
			c++;
		}
	}

	int MIN = min(a, min(b, c));
	a -= MIN;
	b -= MIN;
	c -= MIN;
	if (a > 1 || b > 1 || c > 1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}