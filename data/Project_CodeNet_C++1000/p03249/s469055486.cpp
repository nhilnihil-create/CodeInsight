#include<bits/stdc++.h>
#define maxn 100003
using namespace std;
struct edge{int to,next;}e[maxn<<1];
int head[maxn],cnte,fa[maxn];
void add(int u,int v){e[++cnte].to=v,e[cnte].next=head[u],head[u]=cnte;}
int n,sz[maxn],s[maxn];
long long d[maxn],sum;
map<long long,int> b;
bool cmp(int x,int y){return d[x]<d[y];}
void dfs(int u,int depth){
	sum+=depth;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa[u])continue;
		dfs(v,depth+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",d+i),s[i]=i,b[d[i]]=i,sz[i]=1;
	sort(s+1,s+n+1,cmp);
	for(int i=n;i>=2;i--){
		int v=s[i];
		long long d_u=d[v]-(n-sz[v])+sz[v];
		if(d_u>=d[v]||!b.count(d_u)){puts("-1");return 0;}
		int u=b[d_u];
		add(u,v),add(v,u),fa[v]=u;
		sz[u]+=sz[v];
	}
	if(cnte!=(n-1)*2){puts("-1");return 0;}
	dfs(s[1],0);
	if(sum!=d[s[1]]){puts("-1");return 0;}
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(v==fa[u])continue;
			printf("%d %d\n",u,v);
		}
	}
	return 0;
}
//sykakioi