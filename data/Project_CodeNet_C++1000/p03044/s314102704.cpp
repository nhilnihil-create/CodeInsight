#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
struct edge
{
	int next,to,sum;
	edge(){}
	edge(int x,int y,int z):next(x),to(y),sum(z){}
}e[maxn*2];
int h[maxn],cnt;
void build(int x,int y,int z)
{
	e[++cnt]=edge(h[x],y,z);
	h[x]=cnt;
}
int n,ans[maxn];
void dfs(int x,int fa)
{
	int y;
	for(int i=h[x];i;i=e[i].next)
	{
		y=e[i].to;
		if(y==fa)continue;
		if(e[i].sum&1)ans[y]=ans[x]^1;
		else ans[y]=ans[x];
		dfs(y,x);
	}
}
int main()
{
	int x,y,z;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		build(x,y,z),build(y,x,z);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}