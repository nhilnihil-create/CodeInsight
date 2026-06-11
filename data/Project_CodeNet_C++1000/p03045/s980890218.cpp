#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int cnt,head[maxn],vis[maxn],ans,n,m;
struct fdfdfd{int next,to;}e[maxn<<1];
void addedge(int x,int y){e[++cnt].to=y; e[cnt].next=head[x]; head[x]=cnt;}
void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v]) dfs(v);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i) scanf("%d%d%d",&u,&v,&w),addedge(u,v),addedge(v,u);
	for(int i=1;i<=n;++i)
		if(!vis[i]) ++ans,dfs(i);
	printf("%d\n",ans);
	return 0;
}