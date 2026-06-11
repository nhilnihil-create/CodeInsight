#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

vector<int> G[(int)1e5 + 5];

int color[(int)1e5 + 5];
ll N, M;

bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        // 隣接している頂点が同じ色
        if (color[G[v][i]] == c) return false;

        // 隣接している頂点がまだ塗られていない
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }

    return true;
}

int main() {
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 二部グラフかどうかの判定フラグ
    bool nibu = true;
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                nibu = false;
                break;
            }
        }
    }

    if (nibu) {
        // 二部グラフの場合、異なる色通しで辺ができる
        // b2: 黒色で塗る
        // w2: 白色で塗る

        // // 1. 通らないパターン
        // ll b2 = 0, w2 = 0;
        // b2 = N / 2;
        // w2 = N - b2;

        // 2. 通るパターン (1個ずつカウントアップ)
        ll b2 = 0, w2 = 0;
        rep(i, N) {
            if (color[i] == 1) {
                b2++;
            } else {
                w2++;
            }
        }
        b2 = N - w2;
        // w2 = N - b2; (置き換えても通る)

        ll ans = b2 * w2 - M;
        cout << ans << endl;
    } else {
        // 全部の辺 - M
        ll ans = N * (N - 1) / 2;
        ans -= M;

        cout << ans << endl;
    }
}