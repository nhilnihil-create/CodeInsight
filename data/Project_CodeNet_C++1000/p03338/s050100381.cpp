#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll test[1234][1234];
signed main() {
	ll n = 0, a, cnt = 1, ans = 0; string s; cin >> n >> s;
	for (int h = 1; h < n; h++) {
		vector<ll> v(27); ll sum = 0;
		for (int i = 0; i < h; i++) { v[(int)(s[i]) - 97] = 1; }
		for (int i = h; i < n; i++) {
			if (v[(int)(s[i]) - 97] == 1) { v[(int)(s[i]) - 97] = 0; sum++; }
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	cin >> n; return 0;
}