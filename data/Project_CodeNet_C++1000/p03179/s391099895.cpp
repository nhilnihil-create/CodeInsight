/*
	TRUST THE PROCESS....
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
#define mx 1e18
#define pb push_back
#define read(n) scanf("%d",&n)
#define prll int(x) prll intf("%d",x)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<ll int,ll int>
#define ff first
#define ss second

int main()
{


	ll int n;
	cin>>n;

	string s;
	cin>>s;

	ll int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	ll int predp[n+1][n+1];
	memset(predp,0,sizeof(predp));

	dp[1][1]=1LL;
	predp[1][1]=1LL;
	for(ll int i=1;i<=n;i++)
		predp[1][i]=1LL;

	for(ll int i=2;i<=n;i++)
	{
		for(ll int j=1;j<=i;j++)
		{
			if(s[i-2] == '<')
			{
				dp[i][j] = predp[i-1][j-1];
			}
			else
			{
				dp[i][j] = predp[i-1][n] - predp[i-1][j-1] + md;
			}
			dp[i][j]%=md;
		}
		for(ll int j=1;j<=n;j++)
			predp[i][j] = predp[i][j-1] + dp[i][j] , predp[i][j]%=md;
	}	

	ll int ans=0;
	for(ll int i=1;i<=n;i++)
		ans+=dp[n][i],ans%=md;

	cout<<ans<<endl;

	return 0;
}
