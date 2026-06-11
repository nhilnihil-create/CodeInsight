#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long LL;

const int maxn=2e5+5;

int n;

int tot,go[2*maxn],nxt[2*maxn],f1[maxn];
void ins(int x,int y)
{
	go[++tot]=y;
	nxt[tot]=f1[x];
	f1[x]=tot;
}

int dis[maxn],d[maxn];
int bfs(int x)
{
	memset(dis,0,sizeof(dis));
	d[1]=x;
	dis[x]=1;
	for(int i=1, j=1; i<=j; i++)
	{
		for(int p=f1[d[i]]; p; p=nxt[p]) if (!dis[go[p]])
		{
			dis[go[p]]=dis[d[i]]+1;
			d[++j]=go[p];
		}
	}
	
	int re=0;
	fo(i,1,n) if (dis[i]>dis[re]) re=i;
	return re;
}

int main()
{
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		ins(x,y), ins(y,x);
	}
	
	int x=bfs(1), y=bfs(x), ds=dis[y]-2;
	
	puts((ds>=0 && ds%3==0) ?"Second" :"First" );
}