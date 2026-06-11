#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
ll int gcd (ll int a,ll int b) { return b ? gcd (b, a % b) : a; }

int main()
{
	string a,b;
	cin>>a;	cin>>b;
	int n = a.size(),m=b.size();
	int dp[n+1][m+1];	//n rows, m columns
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i <= m; ++i)
	{
		dp[0][i] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			//cout<<i<<" "<<j<<" : "<<dp[i][j]<<"\n";
		}
	}
	int len = dp[n][m];
	//cout<<dp[n][m]<<"\n";
	string ans;
	int i = n,j=m;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans.push_back(a[i-1]);
			i--;j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else
			j--;
	}
	//cout<<ans.size()<<"\n";
	reverse(ans.begin(), ans.end());
	cout<<ans<<"\n";
	return 0;
}