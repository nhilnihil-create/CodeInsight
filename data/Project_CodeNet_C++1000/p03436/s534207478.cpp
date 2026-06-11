/*
　　こんにちは。あたしはｶｳｶﾞｰﾙ。
　　RedcoderになるためAtCoderを巡る旅をしてます。

　　　 　＿_
　　　 ヽ|＿_|ノ　　　　ﾓｫ
　　　　||‘‐‘||ﾚ　　_)_, ―‐ 、
　　　　/(Ｙ (ヽ＿ /・ ヽ　　   ￣ヽ
　　　　∠ ＿ ゝ　 ｀^ヽ ﾉ.::::_(ノヽ
　　　　 _/ヽ　 　　  /ヽ￣￣￣/ヽ
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl

#define rep(i, n) REP(i, 0, n)                  // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++) // x, x + 1, ..., n-1
#define FOREACH(x, a) for(auto &(x) : (a))

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define COUT(x) cout << (x) << endl

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> board(H);
    vector<vector<int>> dist(H, vector<int>(W, -1));

    rep(i, H) cin >> board[i];

    int cnt = 0;
    rep(i, H) rep(j, W) {
        if(board[i][j] == '#') cnt++;
    }

    queue<pair<int, int>> que;
    dist[0][0] = 0;
    que.push({0, 0});

    while(!que.empty()) {
        pair<int, int> next = que.front();
        que.pop();
        int y = next.first, x = next.second;
        if(y == H - 1 && x == W - 1) break;

        rep(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W || dist[ny][nx] != -1)
                continue;
            if(board[ny][nx] == '#') continue;

            dist[ny][nx] = dist[y][x] + 1;
            que.push({ny, nx});
        }
    }

    int rel = dist[H - 1][W - 1];
    if(rel == -1)
        COUT(-1);
    else
        COUT(H * W - (rel + 1) - cnt);
}
