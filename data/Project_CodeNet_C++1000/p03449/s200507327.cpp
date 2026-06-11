#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int n,dp[2][105];
int main()
{
	cin >> n;
	for(int i=1; i<=n; i++) cin >> dp[0][i],dp[0][i]+=dp[0][i-1]; 
	for(int i=1; i<=n; i++) cin >> dp[1][i],dp[1][i]+=max(dp[1][i-1],dp[0][i]);
	cout << dp[1][n];
	return 0;
}
