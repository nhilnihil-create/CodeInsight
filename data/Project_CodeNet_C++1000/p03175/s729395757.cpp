#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define MAXN 100005

using namespace std;

const int mod = 1e9 + 7;

vector<int> graph[MAXN], g[MAXN];
int dp[MAXN];
bool visited[MAXN];

int add(int a, int b) {

    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}

int mul(int a, int b) {

    ll x = (ll)a * (ll)b;
    x %= mod;
    return (int)x;
}

void dfs(int u) {

    visited[u] = true;
    for(int v: g[u]) {
        if(!visited[v]) {
            graph[u].pb(v);
            dfs(v);
        }
    }
}

int sol(int u) {

    if(dp[u])
        return dp[u];
    
    int ans1 = 1, ans2 = 1;
    for(int v: graph[u]) {
        ans1 = mul(ans1, sol(v));

        for(int p: graph[v])
            ans2 = mul(ans2, sol(p));
    }

    return (dp[u] = add(ans1, ans2));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);

    cout << sol(0) << endl;
    return 0;
}
