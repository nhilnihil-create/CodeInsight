#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int cnt,head[maxn],flag[maxn];
struct fdfdfd{int next,to,w;}e[maxn<<1];
void addedge(int u,int v,int w){e[++cnt].to=v; e[cnt].w=w; e[cnt].next=head[u]; head[u]=cnt;}
void dfs(int u,int pre,int op)
{
	flag[u]=op;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to,w=e[i].w;
		if(v==pre) continue;
		dfs(v,u,w&1?op^1:op);
	}
}
int main()
{
	int n; scanf("%d",&n);
	for(int i=1,u,v,w;i<n;++i) scanf("%d%d%d",&u,&v,&w),addedge(u,v,w),addedge(v,u,w);
	dfs(1,0,0);
	for(int i=1;i<=n;++i) printf("%d\n",flag[i]);
}