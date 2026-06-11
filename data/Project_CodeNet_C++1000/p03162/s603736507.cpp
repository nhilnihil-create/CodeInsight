#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

ll dp[100005][3];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		dp[i][0] = max(dp[i - 1][1] + a, dp[i - 1][2] + a);
		dp[i][1] = max(dp[i - 1][0] + b, dp[i - 1][2] + b);
		dp[i][2] = max(dp[i - 1][1] + c, dp[i - 1][0] + c);
	}
	ll ans = 0;
	rep(i, 3) ans = max(ans, dp[n][i]);
	cout << ans << endl;
}