#include <bits/stdc++.h>

using namespace std;

void dfs(const int cur, const int prev, const vector<vector<int>> &G, vector<int> &ans, const vector<int> &cost, int& ptr) {
    ans[cur] = cost[ptr++];
    for (auto nxt : G[cur]) if (nxt != prev) {
        dfs(nxt, cur, G, ans, cost, ptr);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<int> c(N);
    for_each(begin(c), end(c), [](auto &e) {
        cin >> e;
    });
    sort(rbegin(c), rend(c));

    vector<int> ans(N);
    int tmp = 0;
    dfs(0, -1, G, ans, c, tmp);

    int M = 0;
    for (int i = 1; i < N; i++) {
        M += c[i];
    }

    printf("%d\n", M);
    for (int i = 0; i < N; i++) {
        printf("%d%c", ans[i], (i + 1 == N ? '\n' : ' '));
    }
}
