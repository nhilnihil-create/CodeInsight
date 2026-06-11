#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
ll int gcd (ll int a,ll int b) { return b ? gcd (b, a % b) : a; }

ll int mod = 1e9+7;

int main()
{
	ll int n,m;
	cin>>n>>m;
	int a[n][m];
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;j++)
		{
			char x; cin>>x;
			if(x=='.')
				a[i][j]=1;
			else
				a[i][j]=-1;
		}
	}
	if(a[0][0]==-1)
		return 0;
	int dp[n][m];
	memset(dp,0,sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		if(a[i][0]!=-1)
			dp[i][0]=1;
		else
			break;
	}
	for (int i = 0; i < m; ++i)
	{
		if(a[0][i]!=-1)
			dp[0][i]=1;
		else
			break;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(a[i][j-1]!=-1)
				dp[i][j]+=dp[i][j-1];
			if(a[i-1][j]!=-1)
				dp[i][j]+=dp[i-1][j];
			dp[i][j] = dp[i][j] % mod ;
		}
	}
	cout<<dp[n-1][m-1]<<"\n";
}