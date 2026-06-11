#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

vector<int> topologicalSort(vector<vector<int>> &G) {
    int n = G.size();
    vector<int> indegree(n, 0);
    REP(i, 0, n) {
        for (auto g : G[i]) {
            indegree[g]++;
        }
    }

    stack<int> st;
    REP(i, 0, n) if (indegree[i] == 0) st.push(i);

    vector<int> sorted;
    while (!st.empty()) {
        auto v = st.top(); st.pop();
        sorted.push_back(v);
        for (auto g : G[v]) {
            indegree[g]--;
            if (indegree[g] == 0) st.push(g);
        }
    }
    return sorted;
}

int main() {
    int N, M; cin >> N >> M;

    vector<vector<int>> G(N);
    REP(i, 0, N - 1 + M) {
        int u, v; cin >> u >> v;
        G[--u].push_back(--v);
    }

    auto sorted = topologicalSort(G);
    vector<int> idx(N, 0);
    REP(i, 0, sorted.size()) {
        idx[sorted[i]] = i;
    }

    vector<int> ans(N, -1);
    REP(i, 0, N) {
        for (auto g : G[i]) {
            if (ans[g] == -1 || idx[ans[g]] < idx[i]) {
                ans[g] = i;
            }
        } 
    } 

    REP(i, 0, N) cout << ans[i] + 1 << endl;
    return 0;
}