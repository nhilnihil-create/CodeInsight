#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9+7;
const int N = 1e2+10;
const int K = 1e5+10;

ll dp[N][K];
ll p[K];

int main() {
	int n, k;
	cin >> n >> k;

	dp[0][k] = 1;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		
		fill(p, p+K-5, 0);
		/*for(int j = 0; j <= k; j++) {
			p[j] = dp[i][j];
		}
		*/
		for(int j = k; j >= 0; j--) {
			p[max(j-a, 0)] += dp[i][j];
			p[j+1] -= dp[i][j];
			//p[max(j-a, 0)] %= mod;
		}

		ll cnt = 0;
		for(int f = 0; f <= k; f++) {
			cnt += p[f];
			cnt = (cnt+mod)%mod;
			p[f] = cnt;
		}

		for(int j = 0; j <= k; j++) {
			dp[i+1][j] = (p[j]);
		}
	}

	cout << dp[n][0];
}