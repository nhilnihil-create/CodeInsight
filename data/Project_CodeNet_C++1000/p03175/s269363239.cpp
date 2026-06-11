#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define setpr(pp) fixed<<setprecision(pp)
#define FOR(I,N) for(I=0;I<N;++I)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod	%1000000007
#define pi 3.141592653
#define MX 1000000007

struct rec
{
	ll b;
	ll w;
};
rec NX = {1,1};

rec sm(rec a,rec b)
{
	a.b=(a.b*b.w)mod;
	a.w=(a.w*(b.w+b.b)mod)mod;
	return a;
}

rec dfs(vector<ll> adj[],bool vis[],ll x)
{
	vis[x]=1;
	rec tmp = NX;
	ll k,n = adj[x].size();
	int cnt=0;
	for(ll i = 0;i<n;++i)
	{
		k = adj[x][i];
		if(vis[k]==0)
		{
			tmp = sm(tmp,dfs(adj,vis,k));
		}
	}
	return tmp;
}

int main()
{
	IOS;
	ll n,i,x,y;
	cin>>n;
	vector<ll> adj[n+1];
	bool vis[n+1];
	MS0(vis);
	FOR(i,n-1)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rec ans = dfs(adj,vis,1);
	cout<<((ans.b+ans.w)mod);

}