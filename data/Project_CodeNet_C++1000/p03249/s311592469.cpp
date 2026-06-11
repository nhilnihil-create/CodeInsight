// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
using namespace std;
typedef long long ll;

ll read() {
	ll X=0; char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X;
}

const int N=100000+10;

int n,sz[N],dep[N];
pair<ll,int> d[N];
vector<int> E[N];
vector<pair<int,int> > ans;

void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	for (int v:E[u]) if (v!=f) dfs(v,u);
}

int main() {
	n=read();
	for (int i=1;i<=n;++i) d[i]=make_pair(read(),i);
	sort(d+1,d+n+1);
	for (int i=1;i<=n;++i) sz[i]=1;
	for (int i=n;i>1;--i) {
		ll dlt=2*sz[d[i].second]-n+d[i].first;
		int p=lower_bound(d+1,d+n+1,make_pair(dlt,0))-d;
		if (d[p].first!=dlt) { puts("-1"); return 0; }
		int u=d[i].second,v=d[p].second;
		ans.emplace_back(make_pair(u,v));
		E[u].emplace_back(v),E[v].emplace_back(u),sz[v]+=sz[u];
	}
	dep[0]=-1,dfs(d[1].second,0); ll s=0;
	for (int i=1;i<=n;++i) s+=dep[i];
	if (s!=d[1].first) { puts("-1"); return 0; }
	for (auto i:ans) printf("%d %d\n",i.first,i.second);
	return 0;
}
// /jk