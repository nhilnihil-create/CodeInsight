#include<iostream>
using namespace std;
const int mod=1e9+7;
int dp[1001][1001];
int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char c;cin>>c;
			if(c=='#')dp[i][j]=0;
			else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
			dp[1][1]=1;
		}
	cout<<dp[n][m];
	return 0;
}