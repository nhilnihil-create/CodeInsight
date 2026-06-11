#include <algorithm>
#include <cstdio>
#include <vector>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;

const int N=1e5+5;

int n,sz[N]; ll d_rt;

std::vector<int> g[N];

std::pair<ll,int> a[N];

void dfs(int u,int dep){
	d_rt+=dep; for(auto v: g[u]) dfs(v,dep+1);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){ scanf("%lld",&a[i].fi); a[i].se=i; sz[i]=1; }
	std::sort(a+1,a+1+n);
	for(int i=n;i>=2;--i){
		int u=a[i].se; ll d_fa=a[i].fi+2*sz[u]-n;
		int pos=std::lower_bound(a+1,a+1+n,std::mp(d_fa,0))-a;
		if(a[pos].fi!=d_fa){ puts("-1"); return 0; }
		sz[a[pos].se]+=sz[u]; g[a[pos].se].pb(u);
	}
	dfs(a[1].se,0); if(d_rt!=a[1].fi){ puts("-1"); return 0; }
	for(int u=1;u<=n;++u){
		std::sort(g[u].begin(),g[u].end());
		for(auto v: g[u]) printf("%d %d\n",u,v);
	}
	return 0;
}