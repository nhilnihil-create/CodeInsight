
// Problem : G - Longest Path
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_g
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'
#define vi vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define fi first
#define se second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()

const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N = 1e5 + 5;
vi g[N];
ll dp[N] = {0};
vi vis(N, 0);

ll dfs(ll v) {
	vis[v] = true;
	if(g[v].empty()) {
		//leaf
		return dp[v] = 1;
	}
	ll mx = 0;
	for(auto u:g[v]) {
		if(!vis[u]) {
			dp[v] = max(dfs(u) + 1, dp[v]);
		}
		else {
			dp[v] = max(dp[u] + 1, dp[v]);
		}
	}
	return dp[v];
}

int main() {
    SPEED;
    ll n, m;
    cin>>n>>m;
    for(ll i = 0; i < m; i++) {
    	ll u, v;
    	cin>>u>>v;
    	g[u].pb(v);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
    	if(!vis[i]) {
    		ans = max(ans, dfs(i));
    	}
    }
    cout<<ans - 1;
    return 0;
}