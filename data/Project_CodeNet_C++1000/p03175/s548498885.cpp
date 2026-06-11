#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> gr[mx5];
ll dp[mx5][2] = {};
bool vis[mx5] = {};

void dfs(int u, int pa = 0) {
    vis[u] = 1;
    dp[u][0] = dp[u][1] = 1;
    for (int v:gr[u]) {
        if (v != pa) {
            dfs(v, u);
            dp[u][0] = (dp[u][0] * ((dp[v][0] + dp[v][1]) % mod)) % mod;
            dp[u][1] = (dp[u][1] * dp[v][0]) % mod;
        }
    }
}


int main() {
    nfs
    int i, n, u, v;
    cin >> n;
    for (i = 1; i < n; i++) {
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % mod;
}