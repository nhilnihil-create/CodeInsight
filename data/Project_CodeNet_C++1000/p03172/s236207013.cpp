#include<bits/stdc++.h> 
using namespace std;

#define int long long

int M=1e9+7;

signed main() {
	int N,K;
	cin>>N>>K;
	vector<int> candies(N+1);
	for (int i=0;i<N;i++){
		cin>>candies[i];
	}
	vector<vector<int>> dp(N+1,vector<int>(K+1));
	for (int i=0;i<=N;i++) dp[i][0]=1;
	for (int i=1;i<=N;i++){
		vector<int> prefix_sum(K+1);
		prefix_sum[0]=dp[i-1][0];
		for (int j=1;j<=K;j++){
			prefix_sum[j]=(prefix_sum[j-1]%M+dp[i-1][j]%M)%M;
		}
		for (int j=1;j<=K;j++){
			if (j<=candies[i-1]) dp[i][j]=prefix_sum[j];
			else dp[i][j] = (M+prefix_sum[j]-prefix_sum[j-candies[i-1]-1])%M;
		}
	}
	cout<<dp[N][K];
    return 0; 
}
