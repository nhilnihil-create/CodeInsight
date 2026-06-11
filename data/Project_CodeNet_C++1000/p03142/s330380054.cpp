#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
const int MAXN = 1e5 + 2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> adj[MAXN];
    vector<int> adj_inv[MAXN];
    vector<int> deg(MAXN, 0);
    for (int i = 0; i < N-1+M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_inv[v].push_back(u);
        ++deg[u];
    }
    vector<int> ans(MAXN, 0);
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int idx = q.front();
        q.pop();
        for (auto x : adj_inv[idx]) {
            --deg[x];
            if (deg[x] == 0) {
                q.push(x);
                for (auto y : adj[x]) {
                    if (ans[y] == 0) {
                        ans[y] = x;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
