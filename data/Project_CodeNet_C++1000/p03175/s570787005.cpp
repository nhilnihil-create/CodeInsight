//mangesh2102000

#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int 
#define ld long double
#define pb push_back
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); ++it)
#define F first
#define S second
#define mod 1000000007

vector <int> g[100005];
int n;
int dp[100005][2];

int f(int node,int color,int parent)
{
	if(dp[node][color]!=-1)
		return dp[node][color];

	dp[node][color] = 1;

	for(int i=0;i<g[node].size();i++)
	{
		int child = g[node][i];

		if(child == parent)
			continue;

		int tmp;

		if(color == 0)
		{
			tmp = (f(child,1,node)) % mod;
		}
		else
		{
			tmp = (f(child,0,node) + f(child,1,node)) % mod;
		}

		dp[node][color] *= tmp;
		dp[node][color] %= mod;
	}

	return dp[node][color];
}


void solve(int t)
{
	cin >> n;
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	memset(dp,-1,sizeof(dp));

	int ans = f(1,0,0) + f(1,1,0);
    ans %= mod;

    cout << ans;
    //cout << "Case #" << t << ": ";    
}   


int32_t main()
{
    IOS;
    int t;
    t=1;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }

    return 0;
}