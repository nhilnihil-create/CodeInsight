#include <iostream>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i =0;i<n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
const long long int MOD = 1e9 + 7;
using namespace std;
int main(){
	int n, k; cin >> n >> k; vector<int> a(n,0);
	rep(i, n) cin >> a[i];
	vector<vector<long long int>> dp(n+1, vector<long long int>(k+1, 0));
	dp[0][0] = 1; vector<long long int> sum(k + 2, 0);
	rep(i, n) {
		sum[0] = 0;
		rep(j, k+1) sum[j+1] = (sum[j] + dp[i][j]) % MOD;
		rep(j, k+1) dp[i+1][j] = (sum[j+1] - sum[max(0, j - a[i])] + MOD) % MOD;
	}cout << dp[n][k] << endl;
}