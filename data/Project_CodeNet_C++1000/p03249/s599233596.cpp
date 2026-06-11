#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
typedef long long ll;
int n,u[N],v[N],sz[N],cnt,RT;
int head[N],to[N],nxt[N],tot;
ll wd[N];

struct P{ll v;int id;}t[N];
inline bool cmp(const P&A,const P&B)
{return B.v<A.v;}

map<ll,int>d;

inline void lk(int u,int v)
{to[++tot]=v;nxt[tot]=head[u];head[u]=tot;}

void dfs(int x,int dep)
{
	wd[RT]+=dep;
	for(int i=head[x];i;i=nxt[i]) dfs(to[i],dep+1);
}

void dfss(int x){
  for(int i=head[x];i;i=nxt[i]) 
   {wd[to[i]]=wd[x]+n-(sz[to[i]]<<1);dfss(to[i]);}
}

int main(){
	int i,j;ll dr;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%lld",&t[i].v);
		d[t[i].v]=i;t[i].id=i;
		sz[i]=1;
	}
	sort(t+1,t+n+1,cmp);
	for(i=1;i<n;++i){
		dr=t[i].v-n+(sz[t[i].id]<<1);
		if(dr<0 || (sz[t[i].id]<<1)==n || (!d[dr])) {puts("-1");return 0;}
		j=d[dr];u[++cnt]=j;v[cnt]=t[i].id;
		sz[j]+=sz[t[i].id];
	}
	for(i=1;i<n;++i) lk(u[i],v[i]);
	RT=t[n].id;
	dfs(RT,0);dfss(RT);
	for(i=1;i<=n;++i){
		if(wd[t[i].id]!=t[i].v) {puts("-1");return 0;}
	}
	for(i=1;i<n;++i) printf("%d %d\n",u[i],v[i]);
	return 0;
}