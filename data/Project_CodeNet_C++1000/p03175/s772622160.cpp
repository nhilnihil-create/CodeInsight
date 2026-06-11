#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// {black, white}
pair<ll, ll> dfs(map<ll, vector<ll> > &adj, ll a, ll parent) {
    ll all_white = 1;              // current node can be colored black
    ll some_black = 0;              // current node cannot be colored black        

    for(ll b: adj[a]) {
        if(b != parent) {
            pair<ll, ll> p = dfs(adj, b, a);
            // p.first is the number of ways to color the subtree such that 'b' is black
            ll orig = all_white;
            all_white = (orig * p.second) % MOD;
            some_black = (orig * p.first) % MOD + (some_black * (p.first + p.second)%MOD) % MOD;
        }
    }

    return {all_white, all_white + some_black};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t != 0) {
        ll n;
        cin >> n;
        ll a, b;
        map<ll, vector<ll> > adj;
        for(ll i = 0; i < n-1; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        pair<ll, ll> p = dfs(adj, 1, -1);
        cout << (p.first + p.second) % MOD << "\n";
	    t--;
	}
	return 0;
}
