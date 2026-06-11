#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;
	cin >> s;

	string ans = "-1";
	if (s.size() < 26) {

		vector<bool> vec(26, false);
		for (auto& ch : s) {
			vec[ch - 'a'] = true;
		}

		ans = s;
		for (int i = 0; i < 26; i++) {
			if (vec[i]) continue;
			ans += ('a' + i);
			break;
		}
	}
	else {
		for (int i = 25; i > 0; i--) {
			if (s[i] > s[i - 1]) {
				char ch = '~';
				for (int j = i - 1; j < 26; j++) {
					if (s[i - 1] < s[j]) ch = min(ch, s[j]);
				}
				ans = s.substr(0, i - 1) + ch;
				break;
			}
		}
	}

	cout << ans << endl;
}