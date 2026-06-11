#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<int> indegree(N);
    REP(i, N - 1 + M) {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        g[A].push_back(B);
        ++indegree[B];
    }

    vector<int> parent(N);
    queue<int> q;
    REP(i, N) {
        if (indegree[i] == 0) {
            parent[i] = -1;
            q.push(i);
            break;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    REP(i, N) {
        cout << (parent[i] + 1) << '\n'; // 1-based indexing
    }
    cout << flush;

    return 0;
}