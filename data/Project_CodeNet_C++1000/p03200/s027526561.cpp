#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple


signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'B') {
			++cnt;
			ans += (int)s.size() - i;
		}
	}
	ans -= cnt * (cnt + 1) / 2;
	cout << ans << "\n";
	return 0;
}
