#include<iostream>

using namespace::std;
#define int long long int
#define MOD 1000000007
int dp[3005][3005],pre[3005][2];

main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int j=1;j<n;j++)
		dp[0][j]=1;

	for(int i=1;i<n;i++){
		for(int j=1;j<=i+1;j++)
			if(s[i-1]=='<')
				dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=(dp[i-1][i]-dp[i-1][j-1]+MOD)%MOD;
		for(int j=1;j<=n;j++)
			dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
	}
	// int ans=0;
	// for(int i=1;i<=n;i++)
	// 	ans=(ans+dp[n-1][i])%MOD;
	// cout<<ans<<'\n';
	cout<<dp[n-1][n]<<'\n';
	// for(int j=n;j>0;cout<<'\n',j--)
	// 	for(int i=0;i<n;i++)
	// 		cout<<dp[i][j]<<' ';
}