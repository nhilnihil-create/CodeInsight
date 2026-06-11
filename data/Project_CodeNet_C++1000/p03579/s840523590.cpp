#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define int long long 
const int N=300009;
int ver[N<<1],nxt[N<<1],h[N],tot;
int n,m,col[N],cnt[2];
bool vis[N];

inline void add(int x,int y)
{
	ver[++tot]=y,nxt[tot]=h[x],h[x]=tot;
}

void dfs(int u,int fa)
{
	if(col[u]==col[fa])
	{
		printf("%lld",n*(n-1)/2-m);
		exit(0);
	}
	if(col[u]==!col[fa]) return;
	col[u]=col[fa]^1;
	cnt[col[u]]++;
	vis[u]=true;
	for(int i=h[u];i;i=nxt[i])
	{
		int v=ver[i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y),add(y,x);
	}
	memset(col,-1,sizeof col);
	col[0]=0;
	dfs(1,0);
	// puts("Debug");
	printf("%lld",cnt[0]*cnt[1]-m);
	return 0;
}