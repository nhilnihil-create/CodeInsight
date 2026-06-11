#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;  // 隣接リスト
vector<int> color;

bool dfs(int i, int c) {
    color[i] = c;
    for (auto j : G[i]) {
        if (color[j] == c) {
            return false;
        } else if (color[j] == 0) {
            if (!dfs(j, -c)) return false;
        }
    }
    return true;
}

bool bipartiteCheck() {   
    for (int i = 0; i < n; i++) color[i] = 0;
    return dfs(0, 1);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M;
    scanf("%d %d", &n, &M);
    G.resize(n);
    color.resize(n);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 二部グラフ判定
    if (bipartiteCheck()) {
        int B = 0, W = 0;
        for (auto c : color) {
            if (c == 1)
                B++;
            else
                W++;
        }
        cout << (int64_t) B * W - M << endl;
    } else {
        cout << (int64_t) n * (n - 1) / 2 - M << endl;
    }

    return 0;
}
