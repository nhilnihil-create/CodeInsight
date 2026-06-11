#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> W;
vector<int> dist;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (visited[v]) continue;
        dist[v] = dist[u] + W[u][i];
        dfs(v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> L(M), R(M), D(M);
    G.resize(N); W.resize(N);
    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        L[i] = l; R[i] = r; D[i] = d;
        G[l].push_back(r); W[l].push_back(d);
        G[r].push_back(l); W[r].push_back(-d);
    }

    dist.resize(N);
    visited.resize(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < M; i++) {
        if (D[i] != dist[R[i]] - dist[L[i]]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}