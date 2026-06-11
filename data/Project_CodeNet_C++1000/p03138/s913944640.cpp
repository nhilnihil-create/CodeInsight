
// D - XXOR

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll dp[51][2]; // dp[i][j]: fの左からi桁目までの和の最大値（j:未満フラグ）
ll B[51]; // S[i][j]: Kの左からi桁目がjのときのfのi桁目が1の数
ll S[51][2]; // S[i][j]: Kの左からi桁目がjのときのfのi桁目の和
ll k[51];

int main() {
	ll N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		ll A;
		cin >> A;
		for (int i=50; i>0; i--) {
			B[i] += A % 2;
			A /= 2;
		}
	}

	/*
	// **** debug ****
	for (int i=0; i<=50; i++) {
		cout << "B[" << i << "] = " << B[i] << endl;
	}
	*/

	for (int i=1; i<=50; i++) {
		S[i][0] = B[i] * pow(2, 50-i);
		S[i][1] = (N - B[i]) * pow(2, 50-i);
	}

	/*
	// **** debug ****
	for (int i=0; i<=50; i++) {
		cout << "S[" << i << "][0] = " << S[i][0] << endl;
		cout << "S[" << i << "][1] = " << S[i][1] << endl;
	}
	*/


	for (int i=50; i>0; i--) {
		k[i] = K % 2;
		K /= 2;
	}

	for (int i=1; i<=50; i++) {
		// 未満フラグ1からの遷移
		if (dp[i-1][1] > 0) {
			dp[i][1] = dp[i-1][1] + max(S[i][0], S[i][1]);
		}

		// 未満フラグ0からの遷移
		if (k[i] == 1) {
			dp[i][0] = dp[i-1][0] + S[i][1];
			dp[i][1] = max(dp[i][1], dp[i-1][0] + S[i][0]);
		} else {
			dp[i][0] = dp[i-1][0] + S[i][0];
		}

		/*
		// **** debug ****
		cout << "i=" << i << endl;
		cout << "k[i]=" << k[i] << endl;
		cout << "dp[i][0]=" << dp[i][0] << endl;
		cout << "dp[i][1]=" << dp[i][1] << endl;
		*/
	}

	ll ans = max(dp[50][0], dp[50][1]);

	cout << ans << endl;

	return 0;
}