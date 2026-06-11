// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+10, maxm=5e4+10, lg=21, mod=1e9+7, inf=1e18;

ll n,vv,h[maxn];
vector<ll> g[maxn];
void dfs(ll v=1,ll p=0){
	h[v]=h[p]+1;
	if(h[v]>h[vv]) vv=v;
	for(auto u:g[v])if(u!=p) dfs(u,v);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<n;i++){
		ll v,u; cin>>v>>u;
		g[v].pb(u), g[u].pb(v);
	}
	dfs(),dfs(vv);
	if((h[vv]-1)%3==1) cout<<"Second";
	else cout<<"First";
	
	return 0;
}




