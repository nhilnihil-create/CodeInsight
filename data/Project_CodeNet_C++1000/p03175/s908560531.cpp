#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))

ll n;
vector<ll>adj[100001];
ll dp[100001][2];

// 0 -> black_color
// 1 -> white_color

ll totalWays(ll node,ll parent,ll color)
{
	if(dp[node][color]!=-1) return dp[node][color];
	ll total=1;
	for(auto child : adj[node])
	{
		ll count=0;
		if(child!=parent)
		{
			if(color==0)
				count+=totalWays(child,node,1)%MOD;
			else
				count+=totalWays(child,node,0)+totalWays(child,node,1)%MOD;

			total=((total%MOD)*(count%MOD))%MOD;
		}
	}
	dp[node][color]=total%MOD;
	return total%MOD;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll i,u,v;
    for(i=0;i<n-1;i++)
    {
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    mem(dp,-1);
    cout<<(totalWays(1,-1,0)%MOD+totalWays(1,-1,1)%MOD)%MOD;
    return 0;
}