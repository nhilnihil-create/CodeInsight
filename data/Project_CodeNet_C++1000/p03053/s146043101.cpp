//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
vector<int> dx = {-1, 1,  0, 0};
vector<int> dy = { 0, 0, -1, 1};

const int INF = 1e9;

int main () {
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char> (w));
    vector<vector<int>> num(h, vector<int> (w, INF));
    queue<P> que;
    rep(y, h) rep(x, w) {
        cin >> a[y][x];
        if (a[y][x] == '#') {
            que.push({x, y});
            num[y][x] = 0;
        }
    }

    while (!que.empty()) {
        P p = que.front(); que.pop();
        int x = p.first, y = p.second;
        rep(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (num[ny][nx] != INF) continue;
            if (a[ny][nx] == '#') continue;
            a[ny][nx] = '#';
            num[ny][nx] = num[y][x] + 1;
            que.push({nx, ny});
        }
    }
    int ans = 0;
    rep(y, h) rep(x, w) chmax(ans, num[y][x]);
    cout << ans << endl;

    return 0;
}