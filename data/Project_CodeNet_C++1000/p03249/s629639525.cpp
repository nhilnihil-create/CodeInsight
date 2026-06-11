#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define F first
#define S second
#define pb push_back
const ll N = 1e5 + 5, MOD =  1e9 + 7, INF = 1e9 + 10;
const long double PI = acos(-1);
pair <ll, ll> d[N];
map <ll, ll> mp;
vector <ll> adj[N];
ll sz[N];
ll h[N];
bool mrk[N];
ll n;
void dfs(int v){
	mrk[v] = true;
	for(int u : adj[v]){
		if(!mrk[u]){
			h[u] = h[v] + 1;
			dfs(u);
		}
	}
}
bool ok(){
	dfs(d[n].S);
	ll all = 0;
	for (int i = 1; i <= n; i++){
		all += h[i];
	}
	return (all == d[n].F);
}
int main(){
	cin >> n;
	for (ll i = 1; i <= n; i++){
		cin >> d[i].F;
		d[i].S = i;
		mp[d[i].F] = i; 
	}
	sort(d + 1, d + n + 1);
	reverse(d + 1, d + n + 1);
	bool flag = true;
	
	for (ll i = 1; i <= n - 1; i ++){
		int u = d[i].S;
		sz[u] = 1;
		for(ll v : adj[d[i].second]){
			sz[u] += sz[v];
		}
		ll x = d[i].F + 2 * sz[u] - n;
		auto f = mp.find(x);
		if(f == mp.end()) break;
		adj[mp[x]].pb(d[i].second);
	}
	if(ok()){
		for(ll i = 1; i <= n; i ++){
			for(ll u : adj[i]){
				cout << i  << ' ' << u << '\n';
			}
		}
	}
	else{
		cout << "-1\n";;
	}
	
	return 0;
}
