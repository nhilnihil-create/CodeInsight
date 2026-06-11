#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define N 100005
#define mod 1000000007
vector<vector<ll> >G(60);
ll vis[60];ll intime[60],low[60];
ll timer;ll cnt=0;

ll dfs(ll node,ll pa)
{
	vis[node]=1;
	intime[node]=low[node]=timer;
	timer+=1;
	for(auto i:G[node])
	{
		if(i==pa)
		continue;
		if(vis[i])
		{
			low[node]=min(low[node],intime[i]);
		}
		else
		{
			dfs(i,node);
			if(low[i]>intime[node])
			cnt+=1;
			low[node]=min(low[node],low[i]);
		}
	}
	return cnt;
}
int main()
{
	ll n,m;cin>>n>>m;
	while(m--)
	{
		ll x,y;cin>>x>>y;
		G[x].pb(y);G[y].pb(x);
	}
	ll sol=0;
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ll ans=dfs(i,-1);
			sol+=ans;
		}
	}
	cout<<sol<<"\n";
}