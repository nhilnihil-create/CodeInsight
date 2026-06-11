#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll A[n][3];
	for(int i=0;i<n;i++){
		cin>>A[i][0]>>A[i][1]>>A[i][2];
	} 	
	
	ll dp[n+1][3];
	dp[0][0]= A[0][0];
	dp[0][1]= A[0][1];
	dp[0][2]= A[0][2];
	
	for(int i=1;i<n;i++){
		dp[i][0]= max(dp[i-1][1],dp[i-1][2])+A[i][0];
		dp[i][1]= max(dp[i-1][0],dp[i-1][2])+A[i][1];
		dp[i][2]= max(dp[i-1][0],dp[i-1][1])+A[i][2];
	}	
	ll ans= max(dp[n-1][0],dp[n-1][1]);
	ans= max(ans, dp[n-1][2]);
	cout<<ans<<"\n";
	return 0;
}
