#include<cstdio>
int n;
struct node{
	int to,next,v;
}e[200001];
int ans[100001];
int head[100001],cnt;
inline void AddEdge(int u,int v,int val) {
	e[++cnt].to=v;
	e[cnt].v=val;
	e[cnt].next=head[u];
	head[u]=cnt;
}
inline void dfs(int now,int prt,int sum) {
	ans[now]=sum;
	for(int i=head[now];i;i=e[i].next) {
		int lv=e[i].to;
		if(lv!=prt) {
			if(e[i].v%2) dfs(lv,now,sum^1);
			else dfs(lv,now,sum);
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++) {
		scanf("%d %d %d",&u,&v,&w);
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}