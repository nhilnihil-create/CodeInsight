#include <bits/stdc++.h>

#define ff first
#define ss second
#define int long long
#define MOD 1000000007

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int idx, int last){
    //dp[idx][0] = dp[idx][1] = 1;

    for (auto it : adj[idx]){
        if (it==last)
            continue;
        dfs(it, idx);
        dp[idx][0] = (dp[idx][0] * ((dp[it][0]+dp[it][1]) % MOD) ) % MOD;
        dp[idx][1] = (dp[idx][1] * dp[it][0]) % MOD;
    }
}

signed main() {
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    dp.resize(n, vector<int>(2, 1));

    int u, v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1])%MOD;

    return 0;
}