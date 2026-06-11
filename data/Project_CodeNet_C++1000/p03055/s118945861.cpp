#include<bits/stdc++.h>
#define llong long long
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int N = 2e5;
struct Edge
{
	int v,nxt;
} e[(N<<1)+3];
int fe[N+3];
int fa[N+3];
int len[N+3];
int n,en,mx;

void addedge(int u,int v)
{
	en++; e[en].v = v;
	e[en].nxt = fe[u]; fe[u] = en;
}

void dfs(int u)
{
	for(int i=fe[u]; i; i=e[i].nxt)
	{
		int v = e[i].v; if(v==fa[u]) continue;
		fa[v] = u; dfs(v);
		mx = max(mx,len[u]+len[v]+1);
		len[u] = max(len[u],len[v]+1);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<n; i++) {int u,v; scanf("%d%d",&u,&v); addedge(u,v); addedge(v,u);}
	dfs(1);
//	printf("mx=%d\n",mx);
	if(mx%3==1) {puts("Second");}
	else {puts("First");}
	return 0;
}