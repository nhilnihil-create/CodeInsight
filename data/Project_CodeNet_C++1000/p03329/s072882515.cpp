#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> dp(n + 1, 100000000);
	dp[0] = 0;
	vector<ll> cost;
	cost.push_back(1);
	ll tmp;
	tmp = 6;
	while (tmp <= n) {
		cost.push_back(tmp);
		tmp *= 6;
	}
	tmp = 9;
	while (tmp <= n) {
		cost.push_back(tmp);
		tmp *= 9;
	}
	sort(cost.begin(), cost.end());
	for (ll i = 1; i <= n; i++) {		
		for (int j = 0; j < cost.size(); j++) {
			if (i < cost[j]) continue;
			dp[i] = min(dp[i], dp[i - cost[j]] + 1);			
		}
	}
	cout << dp[n] << endl;
	return 0;
}