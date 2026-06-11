#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
string s;
vector<int> adj[N];
int cnt[N][2], alive[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m;
    cin >> s;
    while (m--) {
        int u,v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u][s[v]-'A']++;
        cnt[v][s[u]-'A']++;
    }
    fill_n(alive, n, 1);
    vector<int> bad;
    for (int u = 0; u < n; u++) if (!cnt[u][0] || !cnt[u][1])
        bad.push_back(u);

    while (!bad.empty()) {
        auto u = bad.back(); bad.pop_back();
        alive[u] = 0;
        for (auto v : adj[u]) if (alive[v]) {
            if (--cnt[v][s[u]-'A'] == 0) bad.push_back(v);
        }
    }
    bool ans = 0;
    for (int u = 0; u < n; u++) ans |= alive[u];
    cout << (ans ? "Yes" : "No");

    return 0;
}
