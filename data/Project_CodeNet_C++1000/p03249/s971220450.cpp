#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
ll n;
ll d[MAXN], sum;
vector< ll > adj[MAXN];
map< ll , ll > mp;
int h[MAXN], sz[MAXN];
void dfs(int u){
	sum += h[u];
	for(int i = 0; i < adj[u].size(); i++){
		ll v = adj[u][i];
		h[v] = h[u] + 1;
		dfs(v);
	}
	
	return;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> d[i], mp[d[i]] = (ll)i;
	for( int i = 0; i < MAXN; i ++) sz[i] = 1LL;
	sort(d, d + n, greater<ll>());
	for(int i = 0; i < n - 1; i ++){
		ll ind = mp[d[i]];
		ll s2 = d[i] + 2LL*sz[ind] - n;
		if( mp.count(s2)){
			if( s2 == d[i]) return cout << -1 << endl, 0;
			ll indpar = mp[s2];
			sz[indpar] += sz[ind], adj[indpar].push_back(ind);
		}
		else return cout << -1 << endl, 0;
	}
	h[mp[d[n - 1]]] = 0;
	dfs(mp[d[n - 1]]);
	if( sum != d[n - 1]) return cout << -1 << endl, 0;
	for(int i = 0; i < n; i ++){
		for( int j = 0; j < adj[i].size(); j ++){
			cout << i + 1LL << " " << adj[i][j] + 1LL << endl;
		}
	}
	
	return 0;
}