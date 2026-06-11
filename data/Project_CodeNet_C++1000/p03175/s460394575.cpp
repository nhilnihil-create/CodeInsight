#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

const int mod = 1000000007;
ll dp[100005][3];
P dfs(vector<vector<ll>> &g, int u, int x){
    if(g[u].empty()){
        dp[u][0] = 1;
        dp[u][1] = 1;
        return P(dp[u][0],dp[u][1]);
    }
    if(dp[u][0]!=0)return P(dp[u][0],dp[u][1]);
    ll dp0=1,dp1=1;
    for(int p:g[u]){
        if(p == x)continue;
        P d = dfs(g,p,u);
        (dp0 *= (d.first + d.second)) %= mod;
        (dp1 *= d.first) %= mod;
    }
    dp[u][0] = dp0;
    dp[u][1] = dp1;
    return P(dp0,dp1);
}

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> g(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g,0,-1);
    ll ans = dp[0][0] + dp[0][1];
    ans %= mod;
    cout << ans << endl;
    return 0;
}