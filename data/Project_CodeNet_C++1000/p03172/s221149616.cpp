#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007

int dp[100][100005];
int a[100];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i = 0;i < n; i++){
		cin>>a[i];
	}
	
	for(int i = 0; i <= a[0]; i++){
		dp[0][i] = 1;
	}
	
	for(int i = 1; i < n; i++)
	{
		vector<int> prefix_sum(k+1);
		prefix_sum[0] = dp[i-1][0];
		for(int j = 1; j<=k; j++){
			prefix_sum[j] = (prefix_sum[j-1] + dp[i-1][j]) % mod;
		}
		for(int j = 0; j < k+1; j++){
			if(j > a[i])
				dp[i][j] = (prefix_sum[j] + mod - prefix_sum[j-a[i]-1]) % mod;
			else
				dp[i][j] = prefix_sum[j];
		}
		
	}
	cout << dp[n-1][k];
}
