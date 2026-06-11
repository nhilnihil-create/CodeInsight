#include <bits/stdc++.h>
using namespace std;

const int maxn=55;

int n,m,dfn[maxn],low[maxn],tim,par[maxn],ans;
vector<int> e[maxn];

inline void tarjan(int u,int fa)
{
	par[u]=fa;
	dfn[u]=low[u]=++tim;

	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];

		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(v!=fa) low[u]=min(low[u],dfn[v]);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	tarjan(1,0);

	for(int i=2;i<=n;i++) if(low[i]>dfn[par[i]]) ans++;
	printf("%d",ans);

	return 0;
}