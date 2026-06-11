#include <bits/stdc++.h>
using namespace std;

int main() {
	int s;
	cin >> s;
	int total = 0;
	if (s != 1 && s != 2) {
		while (s != 1) {
			if (s % 2 == 0) {
				total += 1;
				s /= 2;
			}
			else {
				total += 1;
				s = 3 * s + 1;
			}
		}
		cout << total + 2 << endl;
	}
	else if (s == 1 || s == 2) {
		cout << 4 << endl;
	}
}
