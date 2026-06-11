#include<bits/stdc++.h>
using namespace std;

#define ll long
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
#define NL -5000000

vector<ll> adj[100005];
bool vis[100005];
ll dpw[100005];
ll dpb[100005];

void DFS(ll x)
{
	vis[x]=1;
	ll i,n = adj[x].size();
	dpb[x] = dpw[x] = 1;
	for(auto y:adj[x])
	{
		if(vis[y]==0)
		{
			DFS(y);
			dpb[x] = (dpb[x] * dpw[y] )mod;
			dpw[x] = ( dpw[x] * (dpw[y] + dpb[y])mod )mod;
		}
	}
}

int main()
{	IOS;
	ll n,i,j,x,y;
	cin>>n;
	FOR(i,n-1)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	MS0(vis);
	DFS(1);
	cout<<(dpb[1]+dpw[1])mod;
}
