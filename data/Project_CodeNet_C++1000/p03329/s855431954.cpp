#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll six[10], nine[10];
int dp[100010];
int main() {
	int n;
	cin >> n;
	rep(i,10) {
		six[i] = (ll)pow(6,i+1);
		nine[i] = (ll)pow(9,i+1);
	}

	rep(i,n+1) dp[i] = INF;
	dp[0] = 0;
	rep(i,n+1) {
		rep(j,10) {
			if (six[j] > i) continue;
			dp[i] = min(dp[i], dp[i-six[j]]+1);
		}
		rep(j,10) {
			if (nine[j] > i) continue;
			dp[i] = min(dp[i],dp[i-nine[j]]+1);
		}
		if (i > 0) dp[i] = min(dp[i], dp[i-1]+1);
	}
	cout << dp[n] << endl;
	return 0;
}