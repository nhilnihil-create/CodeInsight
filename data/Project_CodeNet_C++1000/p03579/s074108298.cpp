#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,u,v,tot,ans,c[100020],head[100020],sum[3];
bool vis[100020],f;
struct edge{
	int next,v;
}node[200020];
void add(int u,int v){
	tot++;
	node[tot].v=v;
	node[tot].next=head[u];
	head[u]=tot;
}
void dfs(int u,int col){
	cnt++;
	c[u]=col;
	sum[col]++;
	vis[u]=true;
	for(int i=head[u];i;i=node[i].next){
		int v=node[i].v;
		if(!vis[v]) dfs(v,3-col);
		else if(c[u]==c[v]) f=true;
	}
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,1);
			if(!f) ans+=sum[1]*sum[2];
			else ans+=(cnt-1)*cnt/2;
			sum[1]=sum[2]=cnt=f=0;
		}
	}
	printf("%lld",ans-m);
} 