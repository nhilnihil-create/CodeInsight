#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<int> candies(n+1,0);
	for(int i=1;i<=n;i++) {
		cin>>candies[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(k+1));
	dp[0][0] = 1;
	for(int i=1;i<=k;i++) {
		dp[0][i] = 0;
	}
	for(int i=1;i<=n;i++) {
		vector<int> sum(k+1);
		sum[0] = dp[i-1][0];
		for(int j=1;j<=k;j++){
			sum[j] = (sum[j-1] + dp[i-1][j])%mod;
		}
		for(int j=0;j<=k;j++) {
			if(j<=candies[i]) {
				dp[i][j] = sum[j];
			}
			else {
				int uptill = j-candies[i]-1;
				dp[i][j] = (sum[j] - sum[uptill] + mod)%mod;
			}
		}
		sum.clear();
	}
	cout<<dp[n][k];
}