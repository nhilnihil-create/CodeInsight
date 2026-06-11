#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

int dfs(int v, int p, const vector<vector<int>> &G, int &a) {
    int q;
    int m = 0;
    if (p >= 0 && G[v].size() == 1) {
        a = v;
        return 0;
    }
    for (int u : G[v]) {
        if (u == p) continue;
        int k = dfs(u, v, G, q) + 1;
        if (m < k) {
            m = k;
            a = q;
        }
    }
    return m;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    REP(i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int v,u;
    dfs(0, -1, G, v);
    if (dfs(v, -1, G, u) % 3 == 1) {
        puts("Second");
    }
    else {
        puts("First");
    }
    return 0;
}