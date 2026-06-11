#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;

	int st[26];
	int gl[26];
	for (int i = 0; i < 26; i++) {
		st[i] = -1;
		gl[i] = -1;
	}

	for (int i = 0; i < s.length(); i++) {
		int a = s[i] - 'a';
		int b = t[i] - 'a';

		if (st[a] != -1 || gl[b] != -1) {
			if (st[a] != b || gl[b] != a) {
				cout << "No" << endl;
				return 0;
			}
		} else {
			st[a] = b;
			gl[b] = a;
		}
	}
	cout << "Yes" << endl;

	return 0;
}