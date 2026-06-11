#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	if (s.size() == 26) {
		string t = s;
		if (next_permutation(s.begin(), s.end()) == 0) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < 26; i++) {
				cout << s[i];
				if (s[i] != t[i]) {
					cout << endl;
					return 0;
				}
			}
			cout << endl;
		}
	} else {
		bool a[26] = {};
		for (int i = 0; i < s.length(); i++) {
			a[s[i] - 'a'] = true;
		}

		for (int i = 0; i < 26; i++) {
			if (!a[i]) {
				s += ('a' + i);
				cout << s << endl;
				return 0;
			}
		}
	}

	return 0;
}
