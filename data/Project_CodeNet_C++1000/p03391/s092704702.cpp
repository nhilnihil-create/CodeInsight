#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
signed main() {
	int n, a, b, ok = 0, cnt = INF, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a >> b; ans += b;
		if (a != b) { ok = 1; }
		if (a > b) { cnt = min(cnt, b); }
	}
	if (ok == 0) { cout << 0 << endl; return 0; }
	cout << ans - cnt << endl;
	return 0;
}