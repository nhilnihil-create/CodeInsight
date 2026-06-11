#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+2;
int n,m;
struct Edge{
	int to,nxt;
};
Edge edge[maxn<<1];
int cnt,head[maxn];
void addedge(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
bool odd=false;
int col[3],vis[maxn];
void dfs(int u,int color){
	if (vis[u]){
		if (vis[u]!=color) odd=true;
		return;
	}
	vis[u]=color;
	col[color]++;
	for (int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].to;
		dfs(v,3-color);
	}
}
void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,1);
	if (odd) printf("%lld\n",1LL*n*(n-1)/2-m);
	else printf("%lld\n",1LL*col[1]*col[2]-m);
	return 0;
}