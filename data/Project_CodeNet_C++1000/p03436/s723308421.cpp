#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <typename T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long MOD = 1e9 + 7;

int main() {
    int H, W, white = 0;
    cin >> H >> W;
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    vector<vector<char>> m(H, vector<char>(W));
    rep(i, H) rep(j, W) {
        cin >> m[i][j];
        if(m[i][j] == '.') white++;
    }
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;
    dist[0][0] = 0;
    que.push(make_pair(0, 0));
    while(!que.empty()) {
        pair<int, int> cp = que.front();
        int x = cp.second, y = cp.first;
        que.pop();
        rep(di, 4) {
            int nx = x + dx[di];
            int ny = y + dy[di];
            if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if(m.at(ny).at(nx) == '#') continue;

            if(dist.at(ny).at(nx) == -1) {
                que.push(make_pair(ny, nx));
                dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            }
        }
    }

    if(dist[H - 1][W - 1] == -1)
        cout << -1 << endl;
    else
        cout << white - dist[H - 1][W - 1] - 1 << endl;
}