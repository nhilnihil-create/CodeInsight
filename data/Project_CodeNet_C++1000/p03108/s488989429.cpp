// READ & UNDERSTAND
// ll, int overflow, array bounds
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int const mxn=1e5+5;

struct DSU{
	vi par,siz;
	ll cntt=0;
	DSU(int n){
		for(int i=0; i<n+1; i++){
			par.pb(i);
			siz.pb(1);
		}
		cntt = ll(n)*(n-1)/2;
	}
	ll cnt(){
		return cntt;
	}
	int rt(int u){
		if(par[u]!=u)par[u]=rt(par[u]);
		return par[u];
	}
	void merge(int u, int v){
		u=rt(u); v=rt(v);
		if(u==v)return;
		if(siz[v]<siz[u])swap(u,v);
		par[u]=v;
		cntt -= (ll)siz[u] * siz[v];
		siz[v] += siz[u];
		return;
	}
	bool sameset(int u, int v){
		if(rt(u)==rt(v))return 1;
		return 0;
	}
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int n,m,u,v;
	cin >> n >> m;
	vll ans; DSU dsu(n);
	vector<ii>edge;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		edge.pb({u,v});
	}
	ans.pb(dsu.cnt());
	for(int i=m-1; i>0; i--){
		u = edge[i].fi;
		v = edge[i].se;
		if(!dsu.sameset(u,v)){
			dsu.merge(u,v);
		}
		ans.pb(dsu.cnt());
	}
	reverse(all(ans));
	for(ll x:ans)cout << x << endl;
}	
