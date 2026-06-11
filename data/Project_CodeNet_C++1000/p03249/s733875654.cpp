#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,cnt,e,f[N],a[N],id[N],w[N],siz[N],res[N],head[N],link[N],to[N];
bool vis[111111];
bool cmp(int x,int y){return a[x]<a[y];}
void add(int u,int v){to[++e]=v,link[e]=head[u],head[u]=e;}
void dfs1(int u,int dep){
	siz[u]=1,res[id[1]]+=dep;
	for(int i=head[u];i;i=link[i])if(to[i]!=f[u])dfs1(to[i],dep+1),siz[u]+=siz[to[i]];
}
void dfs2(int u){for(int i=head[u];i;i=link[i])if(to[i]!=f[u])res[to[i]]=res[u]+n-2*siz[to[i]],dfs2(to[i]);}
signed main(){
	scanf("%lld",&n),w[0]=-LLONG_MAX;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),id[i]=i,w[i]=a[i],siz[i]=1;
	sort(id+1,id+n+1,cmp),sort(w+1,w+n+1);
	for(int i=n;i>1;i--){
		int x=2*siz[id[i]]-n+a[id[i]],pos=lower_bound(w+1,w+n+1,x)-w;
		if(w[pos]!=x||n-2*siz[id[i]]<=0){printf("-1");return 0;}
		add(id[pos],id[i]),siz[id[pos]]+=siz[id[i]],f[id[i]]=id[pos];
	}
	dfs1(id[1],0),dfs2(id[1]);
	for(int i=1;i<=n;i++)if(a[i]!=res[i]){printf("-1");return 0;}
	for(int i=2;i<=n;i++)printf("%lld %lld\n",f[id[i]],id[i]);
}