#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int n;
long long dp[3001][3001];
string s;
int main()
{
	cin >> n >> s;
	dp[1][1]=1;
	for(int i=2; i<=n; i++)
	{
		if(s[i-2] == '<') for(int j=2; j<=i; j++) dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
		else for(int j=i-1; j; j--) dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
	}
	long long ans=0;
	//for(int i=1; i<=n; cout<<'\n',i++)
	//	for(int j=1; j<=n; j++)
	//		cout << dp[i][j] << ' ';
	for(int i=1; i<=n; i++) ans=(ans+dp[n][i])%MOD;
	cout << ans;
	return 0;
}