#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define endl "\n"
#define MOD 1000000007

ll recurse(ll i, bool color, vector<vector<ll>>& adj, vector<vector<ll>>& dp, ll from) {
    
    if (dp[i][color] != -1) {
        return dp[i][color];
    }
    ll ans = 1;
    for (auto v: adj[i]) {
        if (v != from) {

            ll temp =  recurse(v, true, adj, dp, i);
            if (color) {
                temp = (temp + recurse(v, false, adj, dp, i)) % MOD;
            }
            ans = (ans * temp) %MOD;
        }
    }
    return dp[i][color] = ans;
    
}

int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> adj (n+1);
    for (ll i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<ll>> dp (n+1, vector<ll> (2, -1));

    cout << (recurse(1, true, adj, dp, 0) + recurse(1, false, adj, dp, 0))%MOD << endl;
    

    return 0;
}