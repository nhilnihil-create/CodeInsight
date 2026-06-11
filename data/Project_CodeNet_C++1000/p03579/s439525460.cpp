#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000
vector<int> G[MAX_N+1];
int color[MAX_N+1];

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}


int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    long long res = 0;
    if (dfs(0, 1)) {            // 2部グラフのとき
        // res = 1LL * N/2 * (N/2 + N%2) - M;
        // 2部グラフの2つ集合が均等に別れる保証はない
        long long  s1 = 0, s2 = 0;
        for (int i = 0; i < N; i++) if (color[i] > 0) s1++;
        s2 = N - s1;
        res = s1 * s2 - M;
    } else {
        res = 1LL * N * (N-1) / 2 - M;
    }
    cout << res << endl;

    return 0;
}
