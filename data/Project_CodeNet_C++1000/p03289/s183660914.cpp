#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isLowerCase(char x) {
	if (0 <= (x - 'a') && (x - 'a') <= 25) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	string s; cin >> s;

	if (s[0] != 'A') {
		cout << "WA" << endl;
		return 0;
	}

	int cnt = 0;
	for (int i = 2; i < s.size() - 1; i++) {
		if (s[i] == 'C') cnt++;
	}
	if (cnt != 1) {
		cout << "WA" << endl;
		return 0;
	}
	
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'C') continue;
		if (!isLowerCase(s[i])) {
			cout << "WA" << endl;
			return 0;
		}
	}

	cout << "AC" << endl;
	return 0;
}
