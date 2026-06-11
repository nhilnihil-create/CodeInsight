#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	ll Inf = 1000000000;
	vector<ll> dp(n + 1, Inf); // 回数
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int price = 1; price <= i; price *= 6) {
			dp[i] = min(dp[i], dp[i - price] + 1);
		}
		for (int price = 9; price <= i; price *= 9) {
			dp[i] = min(dp[i], dp[i - price] + 1);
		}		
	}
	cout << dp[n] << endl;
	return 0;
}