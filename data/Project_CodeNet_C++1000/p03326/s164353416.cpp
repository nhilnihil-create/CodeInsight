#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n);
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb(n) push_back(n)
#define pii pair<int,int> 
const int N=1003;
const ll M=1e9+7;
const ll inf=1e18+5;
ll dp[N][N][9];
// Thanks to LeBron
int main()
{
	int n,m;
	scn(n);scn(m);
	ll a[n][3];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			lscn(a[i][j]);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<9;k++)
				dp[i][j][k] = -inf;
		}
	}
	for(int i=0;i<9;i++)
		dp[0][0][i] = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int mask = 0;mask <=7;mask++)
			{
				dp[i+1][j][mask] = max(dp[i+1][j][mask],dp[i][j][mask]);
				ll here = dp[i][j][mask];
				if(mask&1)
					here+=a[i][0];
				else here-=a[i][0];

				if(mask&2)
				{
					here+=a[i][1];

				}
				else
					here-=a[i][1];

				if(mask&4)
					here+=a[i][2];
				else here-=a[i][2];

				dp[i+1][j+1][mask] = max(dp[i+1][j+1][mask],here);
			}
		}
	}

	ll ans = 0;
	for(int i=0;i<8;i++)
		ans = max(ans,dp[n][m][i]);
	lpri(ans);
	
}