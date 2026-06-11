#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s, nice = "BC";
	int n;
	ll ans = 0;
	cin >> s;
	n = s.size(); s = '#' + s + '#';
	int cnta = 0;
	for (int i=1; i<=n; i++) {
		if (s[i] == 'A') {
			cnta ++;
		} else if (s.substr(i, 2) == nice) {
			ans += cnta;
		} else if (s.substr(i-1, 2) != nice) {
			cnta = 0;
		}
	}
	cout << ans;
	return 0;
}