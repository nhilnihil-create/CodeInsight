#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>g[N<<1];
int n,m,vis[N<<1];
char s[N];
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
        if(vis[v]==0)dfs(v);
        if(vis[v]==1){puts("Yes");exit(0);}
    }
    vis[x]=-1;
}
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=0;i<m;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		if(s[u]==s[v])g[u].push_back(n+v),g[v].push_back(n+u);
		else g[u+n].push_back(v),g[v+n].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	puts("No");
	return 0; 
}