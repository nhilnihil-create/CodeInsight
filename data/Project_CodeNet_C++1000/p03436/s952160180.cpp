#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

ll const MAX_N = 100;
ll const MAX_M = 100;

typedef pair<ll, ll> P;

// 入力
char maze[MAX_N][MAX_M + 1];  // 迷路を表す文字列の配列
ll H, W;
ll sx, sy;  // スタートの座標
ll gx, gy;  // ゴールの座標

ll d[MAX_N][MAX_M];

// 移動4方向のベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// (sx, sy)から(gx, gy)への最短距離を求める
// 辿り着けないとINF

int bfs() {
    queue<P> que;

    for (ll i = 0; i < H; i++)
        for (ll j = 0; j < W; j++) d[i][j] = INF;

    que.push(P(sx, sy));
    d[sy][sx] = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();

        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (0 <= nx && nx < W && 0 <= ny && ny < H && maze[ny][nx] != '#' &&
                d[ny][nx] == INF) {
                que.push(P(nx, ny));
                d[ny][nx] = d[p.second][p.first] + 1;
            }
        }
    }

    return d[gy][gx];
}

int main() {
    INIT;

    cin >> H >> W;
    rep(i, H) {
        rep(j, W) { cin >> maze[i][j]; }
    }

    ll ans = 0;
    rep(i, H) rep(j, W) if (maze[i][j] == '.') ans++;

    sx = 0;
    sy = 0;
    gx = W - 1;
    gy = H - 1;
    bfs();
    if (d[gy][gx] == INF) {
        cout << -1 << endl;
    } else {
        cout << ans - d[gy][gx] - 1 << endl;
    }

    // rep(i, H) {
    //     rep(j, W) {
    //         if (d[i][j] >= INF) {
    //             cout << "# ";
    //         } else {
    //             cout << d[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    return 0;
}