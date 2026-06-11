#include<bits/stdc++.h>

using namespace std;

#define N 600000
#define INF 0x3f3f3f3f

int n,m,x,y,z,tot,f[N],head[N];
struct edge{int v,l,nxt;}e[N];

void add(int x,int y,int z){e[++tot].v=y; e[tot].l=z; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int u){
	for (int i=head[u],v;i;i=e[i].nxt)
		if (f[v=e[i].v]==INF){
			f[v]=f[u]+e[i].l;
			dfs(v);
		}
		else
			if (f[v]!=f[u]+e[i].l){puts("No"); exit(0);}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	while (m--){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,-z);
	}
	for (int i=1;i<=n;++i)
		if (f[i]==INF){f[i]=0; dfs(i);}
	puts("Yes");
	
	return 0;
}
			