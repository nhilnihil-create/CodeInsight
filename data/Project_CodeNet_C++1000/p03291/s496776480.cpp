
// D - We Love ABC

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

ll dp[100001][3]; // dp[i][j]: i文字目まででj（0:'A', 1:'AB', 2:'ABC'）を作れる数

ll mod_pow(ll a, ll n, ll mod) {
	ll result = 1;
	while (n > 0) {
		if (n & 1) result = result * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return result;
}

int main() {
	string S;
	cin >> S;

	int N = S.size();
	S = " " + S;
	ll hatena = 0;

	for (int i=0; i<N; i++) {
		if (S[i+1] == 'A') {
			dp[i+1][0] = dp[i][0] + mod_pow(3, hatena, MOD);
			dp[i+1][1] = dp[i][1];
			dp[i+1][2] = dp[i][2];
		}

		if (S[i+1] == 'B') {
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = dp[i][1] + dp[i][0];
			dp[i+1][2] = dp[i][2];
		}

		if (S[i+1] == 'C') {
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = dp[i][1];
			dp[i+1][2] = dp[i][2] + dp[i][1];
		}

		if (S[i+1] == '?') {
			// ? = A
			dp[i+1][0] = dp[i][0] + mod_pow(3, hatena, MOD);
			dp[i+1][1] = dp[i][1];
			dp[i+1][2] = dp[i][2];

			// ? = B
			dp[i+1][0] += dp[i][0];
			dp[i+1][1] += dp[i][1] + dp[i][0];
			dp[i+1][2] += dp[i][2];

			// ? = C
			dp[i+1][0] += dp[i][0];
			dp[i+1][1] += dp[i][1];
			dp[i+1][2] += dp[i][2] + dp[i][1];

			hatena++;
		}

		dp[i+1][0] %= MOD;
		dp[i+1][1] %= MOD;
		dp[i+1][2] %= MOD;

		//cerr << "i=" << i+1 << " A:" << dp[i+1][0] << " AB:" << dp[i+1][1] << " ABC:" << dp[i+1][2] << endl; // **** debug ****
	}

	ll ans = dp[N][2];

	cout << ans << endl;

	return 0;
}