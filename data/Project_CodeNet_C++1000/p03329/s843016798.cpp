#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ll_Inf = 9223372036854775807LL;

int main() {

	ll n; cin >> n;
	vector<ll> c;
	c.push_back(1);
	ll tmp6 = 6;
	while (tmp6 <= n) {
		c.push_back(tmp6);
		tmp6 *= 6;
	}
	ll tmp9 = 9;
	while (tmp9 <= n) {
		c.push_back(tmp9);
		tmp9 *= 9;
	}
	sort(c.begin(), c.end());

	vector<ll> dp(n + 1, ll_Inf);
	dp[0] = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j < c.size(); j++) {
			if (i - c[j] < 0) continue;
			dp[i] = min(dp[i], dp[i - c[j]] + 1);
		}
	}
	cout << dp[n] << endl;
	return 0;
}