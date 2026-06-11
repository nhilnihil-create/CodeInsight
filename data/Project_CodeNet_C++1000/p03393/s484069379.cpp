#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	if (s.size() != 26) {
		for (char c = 'a'; c <= 'z'; c++) {
			bool ok = true;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == c) {
					ok = false;
				}
			}
			if (ok) {
				s.push_back(c);
				cout << s << endl;
				return 0;
			}
		}
	}
	else {
		
		if (s == "zyxwvutsrqponmlkjihgfedcba") {
			cout << -1 << endl;
			return 0;
		}

		map<char, int> mp;
		for (int i = 25; i > 0; i--) {
			mp[s[i]] = 1;
			s.pop_back();
			for (auto x: mp) {
				if (x.first > s[i - 1]) {
					s[i - 1] = x.first;
					cout << s << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}
