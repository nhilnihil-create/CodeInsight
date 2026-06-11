#include <bits/stdc++.h>

using namespace std;

const int N = 110, K = 1e5+100, mod = 1e9+7;
int n, k, a[N], dp[N][K], sum[K];


int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	dp[0][0] = 1; // i , k qtd de doces

	for (int i = 1; i <= n; i++){
		memset(sum, 0, sizeof sum);
		sum[0] = dp[i - 1][0];

		for (int j = 1; j <= k; j++){
			sum[j] = (sum[j - 1] + dp[i - 1][j])%mod;
		}

		for (int j = 0; j <= k; j++){
			int sumj = sum[j], 
				rmv = j - a[i] - 1; // [a[i], j]
			if (rmv >= 0){
				//cout << rmv << endl;
			 	sumj = (sumj - sum[rmv] + mod)%mod;
			 }
			dp[i][j] = sumj;
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}

	printf("%d\n", dp[n][k]);

	return 0; 
}