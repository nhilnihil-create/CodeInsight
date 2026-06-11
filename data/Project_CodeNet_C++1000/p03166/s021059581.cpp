#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];
ll vis[N];
std::vector<ll> v[N], vv;

void dfs(ll node){
	vis[node] = 1;
	for(auto i : v[node]){
		if(!vis[i]){
			dfs(i);
		}
	}
	vv.push_back(node);
}

void solve(){
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		ll a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(vv.begin(), vv.end());
	std::map<ll, ll> mp;
	for (int i = 0; i < vv.size(); ++i){
		for(auto j : v[vv[i]]){
			mp[j] = max(mp[j], mp[vv[i]] + 1);
		}
	}
	ll mx = 0;
	for (int i = 1; i <= n; ++i){
		mx = max(mx, mp[i]);
	}
	cout << mx;
}
 
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
}
// Radhe Radhe