// 2020/4/20

#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<long long>>;

vector<long long> color;
// -1: 未探査, ０: 白, 1: 黒

bool dfs(Graph &G, long long v, int cur = 0) {
    color[v] = cur;

    for (auto next_v : G[v]) {
        // 既に探索済みの場合
        if (color[next_v] != -1) {
            // 色が同じ場合 → 二部グラフではない
            if (color[next_v] == cur) return false;

            // 色が違う場合 → 二部グラフの可能性を残してcontinue。trueは最後に返す。
            continue; 
        }

        // 1回でもふfalseが帰ってきたらfalse。
        if(!dfs(G, next_v, 1 - cur)) return false;
    }

    // 何もなければ最後にTrue！
    return true;
}

int main() {
    long long N, M;
    cin >> N >> M;

    Graph G(N);

    for (long long i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;

        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    color.assign(N, -1);

    bool is_bipartile = true;
    for (long long v = 0; v < N; v++) {
        if (color[v] != -1) continue;  // v が探索済みだったらスルー
        if (!dfs(G, v)) is_bipartile = false;
    }

    long long B = 0, W = 0;  // 黒の数、白の数

    for (long long i = 0; i < N; i++) {
        if (color[i] == 0) W++;
        else B++;
    }

    if (is_bipartile) cout << B * W - M << endl;
    else cout << N * (N - 1) / 2 - M << endl;
}
