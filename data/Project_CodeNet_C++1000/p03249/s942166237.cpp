#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

map<int,int>mmp;
vector<int>g[N];
int d[N],fa[N],pd[N],f[N],n,sz[N];

void dfs1(int x,int s,int dep){
	pd[s]+=dep;
	for(int i=0;i<g[x].size();++i) dfs1(g[x][i],s,dep+1);
}

void dfs2(int x){
	for(int i=0;i<g[x].size();++i){
		pd[g[x][i]]=f[x]-2*sz[g[x][i]]+n;
		dfs2(g[x][i]);
	} 	
}

main(){
	int x,mx=0,cnt=0,a,i;
	scanf("%lld",&n);
	for(i=1;i<=n;++i) scanf("%lld",&d[i]),f[i]=d[i],mmp[d[i]]=i;
	for(i=1;i<=n;++i) sz[i]=1;
	sort(d+1,d+n+1);
	for(i=n;i>1;--i){
		a=mmp[d[i]];
		x=d[i]-(n-sz[a])+sz[a];
		if(x>=d[i]) return printf("-1")&0;
		if(!mmp[x]) return printf("-1")&0;
		fa[a]=mmp[x];
		sz[mmp[x]]+=sz[a];
	}
	for(i=1;i<=n;++i) if(fa[i]) g[fa[i]].push_back(i);
	//judge
	int y=mmp[d[1]];
	dfs1(y,y,0);
	dfs2(y);
	for(i=1;i<=n;++i) if(pd[i]!=f[i]) return printf("-1")&0;
	for(i=1;i<=n;++i) if(fa[i]) printf("%lld %lld\n",fa[i],i);
}