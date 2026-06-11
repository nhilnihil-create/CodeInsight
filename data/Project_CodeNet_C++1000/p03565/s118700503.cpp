#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t, res = "UNRESTORABLE";
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = n - m; i >= 0; i--) {
		bool ok = true;
		for (int j = 0; j < m; j++) {
			if (s[i + j] == t[j] || s[i + j] == '?')
				continue;
			ok = false;
			break;
		}
		if (ok) {
			for (int j = 0; j < m; j++) {
				s[i + j] = t[j];
			}
			for (int j = 0; j < n; j++) {
				if (s[j] == '?')
					s[j] = 'a';
			}
			res = s;
			break;
		}
	}
	cout << res;
	return 0;
}