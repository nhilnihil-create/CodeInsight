#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;
	string t;
	cin >> t;

	map<char, char> ss;
	map<char, char> tt;

	for (int i = 0; i < s.size(); i++) {
		if (ss.count(s[i])) {
			if (ss[s[i]] != t[i]) {
				cout << "No" << endl;
				return 0;
			}
		}
		ss[s[i]] = t[i];
	}
	for (int i = 0; i < t.size(); i++) {
		if (tt.count(t[i])) {
			if (tt[t[i]] != s[i]) {
				cout << "No" << endl;
				return 0;
			}
		}
		tt[t[i]] = s[i];
	}
	cout << "Yes" << endl;

	return 0;

}