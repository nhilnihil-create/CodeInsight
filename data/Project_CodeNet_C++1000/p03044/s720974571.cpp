#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

const ll N = 1e5 + 5;
vector<pii>adj[N];
ll ans[N];

void dfs(ll n, ll p, ll c){
	ans[n] = c;
	for(auto x : adj[n]){
		if(x.ff != p){
			dfs(x.ff,n,c ^ (x.ss&1));
		}
	}
}

void doit(){
	ll n, i, x, y, d;
	cin >> n;
	rep(i,0,n - 1){
		cin >> x >> y >> d;
		adj[x - 1].pb({y - 1, d});
		adj[y - 1].pb({x - 1, d});
	}
	dfs(0,-1, 0);
	rep(i,0,n)cout << ans[i] << nl;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t = 1;
//	 cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
