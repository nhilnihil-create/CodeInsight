#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> C;

void dfs(vector<int> &scores, vector<bool> &visited, int u, int &cnt) {
    scores[u] = C[cnt++];
    visited[u] = true;
    for (int v : G[u]) {
        if (visited[v]) continue;
        dfs(scores, visited, v, cnt);
    }
}

int main() {
    int N;
    cin >> N;
    G.resize(N);
    C.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end(), greater<int>());
    int res = 0;
    for (int i = 1; i < N; i++) res += C[i];
    cout << res << endl;

    int cnt = 0;
    vector<int> scores(N, 0);
    vector<bool> visited(N, false);
    dfs(scores, visited, 0, cnt);

    for (int i = 0; i < N; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}