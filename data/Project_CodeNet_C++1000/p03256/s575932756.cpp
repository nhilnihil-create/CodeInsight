#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct edge{
	int v,nxt;
}g[N<<1];
int tot=0,head[N];
inline void add(int u,int v){
	g[++tot]=edge{v,head[u]}; head[u]=tot;
	g[++tot]=edge{u,head[v]}; head[v]=tot;
}
int n,m,dgr[N][2],q[N],h,t,vis[N];
char s[N];
int main(){
	scanf("%d%d%s",&n,&m,s);
	for(int i=1; i<=m; ++i){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); dgr[u][s[v-1]=='B']++; dgr[v][s[u-1]=='B']++;
	}
	h=t=0; for(int i=1; i<=n; ++i)if(!dgr[i][0]||!dgr[i][1])q[++t]=i,vis[i]=1;
	while(h<t){
		int u=q[++h];
		for(int i=head[u]; i; i=g[i].nxt){
			int v=g[i].v; if(vis[v])continue;
			--dgr[v][s[u-1]=='B'];
			if(!dgr[v][s[u-1]=='B']){
				vis[v]=1; q[++t]=v;
			}
		}
	}
	puts(t==n?"No":"Yes");
	return 0;
}