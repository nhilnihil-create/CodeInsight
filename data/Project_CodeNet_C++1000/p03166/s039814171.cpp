#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1000000000
#define mod 1000000007
vector<ll> ad[100005];
ll dp[100005];

ll dfs(ll i) {
    if(dp[i] != -1) return dp[i];
    bool leaf = 1;
    ll best = 0;
    for(auto x: ad[i]) {
        leaf = 0;
        best = max(best, dfs(x));
    }
    return dp[i] = leaf ? 0 : 1 + best;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll x, y;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        ad[x].push_back(y);
    }
    ll ans = INT_MIN;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, dfs(i));
    }
    cout << ans;
}
