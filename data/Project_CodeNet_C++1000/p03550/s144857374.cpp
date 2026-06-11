#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
	ll N, Z, W;
	cin >> N >> Z >> W;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;
	// dp[i][j] : 山札i番目, j:0は先行, 1は後攻
	vector<vector<ll>> dp(N, vector<ll>(2));
	for(int i=0;i<N;i++) dp[i][0] = LLONG_MIN;
	for(int i=0;i<N;i++) dp[i][1] = LLONG_MAX;
	for(int i=N-1;i>=0;i--) {
		// 0のとき
		ll other = (i ? A[i-1] : W);
		dp[i][0] = max(dp[i][0], llabs(A[N-1] - other));
		for(int j=i+1;j<N;j++) dp[i][0] = max(dp[i][0], dp[j][1]);

		// 1のとき
		other = (i ? A[i-1] : Z);
		dp[i][1] = min(dp[i][1], llabs(A[N-1] - other));
		for(int j=i+1;j<N;j++) dp[i][1] = min(dp[i][1], dp[j][0]);

	}
	cout << dp[0][0] << endl;
}