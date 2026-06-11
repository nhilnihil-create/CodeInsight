#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int sum=0,ff=1; char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		sum=sum*10+(ch^48),ch=getchar();
	return sum*ff;
}

const int N=1e5+5;

int n,m,cnt0,cnt1,head[N],col[N],ans,cnt;
struct nood
{
	int nex,to;
};
nood e[N<<1];

inline void jia(int u,int v)
{
	e[++cnt].nex=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}

inline void dfs(int u,int fa,int co)
{
	if(!col[u]) col[u]=co;
	else 
	{
		if(co!=col[u])
		{
			printf("%lld\n",n*(n-1)/2-m);
			exit(0);
		}
		return;
	}
	
	for ( int i=head[u];i;i=e[i].nex )
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u,co^1);
	}
}

signed main()
{
	n=read();
	m=read();
	for ( int i=1;i<=m;i++ )
	{
		int u,v;
		u=read();
		v=read();
		jia(u,v);
		jia(v,u);
	}
	dfs(1,0,1);
	for ( int i=1;i<=n;i++ ) (col[i])?cnt1++:cnt0++;
	printf("%lld\n",cnt1*cnt0-m);
	return 0;
}