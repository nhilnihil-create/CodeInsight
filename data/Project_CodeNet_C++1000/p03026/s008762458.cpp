#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> C;
vector<int> D;
vector<bool> visited;

void dfs(int u, int &i) {
    D[u] = C[i++];
    visited[u] = true;

    for (int v : G[u]) {
        if (visited[v]) continue;
        dfs(v, i);
    }
}

int main() {
    int N;
    cin >> N;
    G.resize(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    C.resize(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        sum += C[i];
    }

    sort(C.begin(), C.end(), greater<int>());
    int res = sum - C[0];

    D.resize(N, 0);
    visited.resize(N, false);
    int i = 0;
    dfs(0, i);

    cout << res << endl;
    for (int n : D) cout << n << " ";
    cout << endl;

    return 0;
}