#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int szs = s.size();

	bool st1 = true, st2 = false, st3 = false, st4 = false;

	bool ok = true;
	for (int i = 0; i < szs; i++) {
		if (st1) {
			if (s.substr(i, 3) == "KIH") {
				i += 2;
				st1 = false;
				st2 = true;
				continue;
			}
			else if (s.substr(i, 4) == "AKIH") {
				i += 3;
				st1 = false;
				st2 = true;
				continue;
			}
			else {
				ok = false;
				break;
			}
		}
		if (st2) {
			if (s.substr(i, 1) == "B") {
				st2 = false;
				st3 = true;
				continue;
			}
			else if (s.substr(i, 2) == "AB") {
				i++;
				st2 = false;
				st3 = true;
				continue;
			}
			else {
				ok = false;
				break;
			}
		}
		if (st3) {
			if (s.substr(i, 1) == "R") {
				st3 = false;
				st4 = true;
				continue;
			}
			else if (s.substr(i, 2) == "AR") {
				i++;
				st3 = false;
				st4 = true;
				continue;
			}
			else {
				ok = false;
				break;
			}
		}
		if (st4) {
			if (s[i] != 'A' || i != szs - 1) ok = false;
		}
	}

	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}