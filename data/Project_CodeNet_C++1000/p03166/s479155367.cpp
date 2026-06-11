#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
#define mp make_pair
#define pb push_back
using namespace std;
vector<int> graph[100001];
vector<int> dis(100001,-1);
int dfs(int v)
{
	if(dis[v]!=-1)
	{
		return dis[v];
	}
	dis[v]=0;
	for(int child:graph[v])
	{
		dis[v]=max(dis[v],1+dfs(child));
	}
	return dis[v];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>u>>v;
    	graph[u].pb(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    	ans=max(ans,dfs(i));
    }
    cout<<ans<<endl;
}