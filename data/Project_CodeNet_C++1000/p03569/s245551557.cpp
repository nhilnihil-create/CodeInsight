#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int st = 0, ed = s.length() - 1;
	int ans = 0;
	for ( ; st < ed; ) {
		if (s[st] == s[ed]) {
			st++; ed--;
			continue;
		}
		if (s[st] == 'x' && s[ed] == 'x') {
			st++; ed--;
			continue;
		}
		if (s[st] == 'x') {
			ans++;
			st++;
			continue;
		}
		if (s[ed] == 'x') {
			ans++;
			ed--;
			continue;
		}
		if (s[st] != s[ed]) {
			ans = -1;
			break;
		}
		st++; ed--;
	}
	cout << ans << endl;
	return 0;
}
