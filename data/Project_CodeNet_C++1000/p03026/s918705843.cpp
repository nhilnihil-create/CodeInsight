#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> C(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        sum += C[i];
    }

    sort(C.begin(), C.end(), greater<int>());
    int res = sum - C[0];

    vector<int> D(N, 0);
    queue<int> que;
    vector<bool> visited(N, false);
    que.push(0);
    visited[0] = true;
    int cnt = 0;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        D[u] = C[cnt++];
        for (int v : G[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            que.push(v);
        }
    }

    cout << res << endl;
    for (int i = 0; i < N; i++) {
        cout << D[i] << " ";
    }
    cout << endl;

    return 0;
}