#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,cnt,sum,a[N],sz[N],tmp[N],ansx[N],ansy[N];
map<int,int>b;
vector<int>G[N];
inline bool cmp(int x,int y){return a[x]>a[y];}
void dfs(int u,int fa,int dep){
	sum+=dep;
	for (int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if (v==fa) continue;
		dfs(v,u,dep+1);
	}
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),b[a[i]]=i,tmp[i]=i,sz[i]=1;
	sort(tmp+1,tmp+n+1,cmp);
	for (int i=1;i<n;i++){
		int x=tmp[i];
		int dis=a[x]-(n-sz[x])+sz[x];
		if (!b[dis]) return puts("-1"),0;
		int y=b[dis];
		sz[y]+=sz[x];ansx[++cnt]=x;ansy[cnt]=y;
		if (x==y) return puts("-1"),0;
		G[y].push_back(x);
	}
	int rt=tmp[n];sum=0;
	dfs(rt,-1,0);
	if (sum!=a[rt]) return puts("-1"),0;
	for (int i=1;i<=cnt;i++) printf("%lld %lld\n",ansx[i],ansy[i]);
	return 0;
}