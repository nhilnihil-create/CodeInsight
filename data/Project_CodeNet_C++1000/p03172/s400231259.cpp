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
	vector<int>dp(K+1);
	dp[0]=1;
	for (int i=1;i<=N;i++){
		vector<int> prefix_sum(K+1);
		prefix_sum[0]=dp[0];
		for (int j=1;j<=K;j++){
			prefix_sum[j]=(prefix_sum[j-1]%M+dp[j]%M)%M;
		}
		for (int j=K;j>=0;j--){
			if (j<=candies[i-1]) dp[j]=prefix_sum[j];
			else dp[j] = (M+prefix_sum[j]-prefix_sum[j-candies[i-1]-1])%M;
		}
	}
	cout<<dp[K];
    return 0; 
}
