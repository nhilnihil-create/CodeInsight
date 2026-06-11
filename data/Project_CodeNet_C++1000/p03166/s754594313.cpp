#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
vector <ll> vis(N+5,0),in_deg(N+5,0),out_deg(N+5,0),depth(N+5,0);
vector <ll> G[N+5];
void dfs(ll node)
{
	for(auto child:G[node])
	{
		if(depth[child]==0)
		{
			dfs(child);
			depth[node] = max(depth[node],1 + depth[child]);
		}
		else
			depth[node] = max(depth[node],1+depth[child]);
	}
	return;
}
int main()
{
    IO
	clock_t begin = clock();
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
    	ll p,q;
    	cin>>p>>q;
    	G[p].push_back(q);
    	in_deg[q]++;
    	out_deg[p]++;
    }
    ll ma = 0;
    for(ll i=1;i<=n;i++)
    {
    	if(!in_deg[i])
    	{
    		dfs(i);
    		ma = max(ma,depth[i]);
    	}
    }
    cout<<ma<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}