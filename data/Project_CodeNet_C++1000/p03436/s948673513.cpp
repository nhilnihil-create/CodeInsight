// https://atcoder.jp/contests/abc088/tasks/abc088_d
#include <bits/stdc++.h>

using namespace std;
// #define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

using pii = pair<int, int>;
const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// 第1引数はtrueの箇所のみ通行可能、第2引数はスタート、第3引数はゴール
// 戻り値はスタートからゴールまでの最短距離。到達不可の場合は-1
int bfs(vector<vector<bool>> flags, pii start, pii end) {
    queue<tuple<int, int, int>> q;
    q.push({start.first, start.second, 0});
    // 後戻りを防ぐため壁にする
    flags[start.first][start.second] = false;
    // 到達不可能の場合は-1
    int ret = -1;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int y = get<0>(t);
        int x = get<1>(t);
        int d = get<2>(t);
        if (y == end.first && x == end.second) {
            ret = d;
            break;
        }
        for (auto &a : dir) {
            int ny = y + a.first;
            int nx = x + a.second;
            if (flags[ny][nx]) {
                q.push({ny, nx, d + 1});
                // 後戻りを防ぐため壁にする
                flags[ny][nx] = false;
            }
        }
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Y, X;
    cin >> Y >> X;
    // 周囲を壁扱いにするため+2する
    vector<vector<bool>> flags(Y + 2, vector<bool>(X + 2));
    int wall = 0;
    FOR(y, 1, Y + 1) {
        string s;
        cin >> s;
        REP(x, s.size()) {
            if (s[x] == '.') {
                flags[y][x + 1] = true;
            } else {
                // 壁の数をカウント
                wall++;
            }
        }
    }
    int ans = bfs(flags, {1, 1}, {Y, X});
    // 到達不可
    if (ans == -1) {
        cout << -1 << endl;
    } else {
        // スタート位置は黒くできないので-1
        cout << Y * X - wall - 1 - bfs(flags, {1, 1}, {Y, X}) << endl;
    }

    return 0;
}
