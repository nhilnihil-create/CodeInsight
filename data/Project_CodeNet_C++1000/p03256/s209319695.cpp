#include <cstdio>
#include <queue>

const int N=2e5+5,M=4e5+5;
int n,m,tot,lnk[N],ter[M],nxt[M],deg[N][2];
char col[N];
bool vis[N];

void add(int u,int v) {
	ter[++tot]=v,nxt[tot]=lnk[u],lnk[u]=tot;
}
bool check() {
	for(int i=1;i<=n;++i) if(!vis[i]) return 0;
	return 1;
}
int main() {
	scanf("%d%d%s",&n,&m,col+1);
	while(m--) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
		++deg[u][col[v]=='B'];
		++deg[v][col[u]=='B'];
	}
	std::queue<int> q;
	for(int i=1;i<=n;++i) {
		if(!deg[i][0]||!deg[i][1]) q.push(i),vis[i]=1;
	}
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for(int i=lnk[u];i;i=nxt[i]) {
			int v=ter[i];
			if(vis[v]) continue;
			if(!--deg[v][col[u]=='B']) q.push(v),vis[v]=1;
		}

	}
	puts(check()?"No":"Yes");
	return 0;
}