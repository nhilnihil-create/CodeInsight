#include<bits/stdc++.h>
#define ll  long long int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define inf 100000000000000000LL
#define fast_io	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
using namespace std;

void addEdge(vector<ll> g[],ll x,ll y)
{
	g[x].pb(y);
	g[y].pb(x);

}
ll dfs(vector<ll> graph[],ll visited[][2],ll val,ll col)
{
	if(visited[val][col]==-1)
	{	
		ll s=0;
		ll p=1;
		for(ll i=0;i<graph[val].size();i++)
		{
	
			s=((col==0)?0:dfs(graph,visited,graph[val][i],col))%mod+dfs(graph,visited,graph[val][i],!col)%mod;
			s=s%mod;
			p=(p%mod*s%mod)%mod;
		}

		if(graph[val].size()==0)
		return 1;
		visited[val][col]=p%mod;
		return visited[val][col];
	}
	else
	return visited[val][col];
}
void directed(vector<ll> g[],vector<ll> graph[],ll *v,ll val)
{
	if(v[val]==-1)
	{
		v[val]=1;
		
		for(ll i=0;i<g[val].size();i++)
		{
			if(v[g[val][i]]==-1)
			{
				graph[val].pb(g[val][i]);
				directed(g,graph,v,g[val][i]);
			}
		}
	}

}
int main()
{
	ll n,x,y;
	cin>>n;
	
	vector<ll> g[n+1];
	vector<ll> graph[n+1];
	
	ll visited[n+1][2];
	ll v[n+1];
	
	memset(v,-1,sizeof(v));
	memset(visited,-1,sizeof(visited));
	
	for(ll i=1;i<n;i++)
	{
		cin>>x>>y;
		addEdge(g,x,y);
	}
	directed(g,graph,v,1);

	ll s1=(dfs(graph,visited,1,0)%mod+dfs(graph,visited,1,1)%mod)%mod;
	cout<<s1<<endl;
}