#include <bits/stdc++.h>
#define repp(i, l, r) for (long long i = (l); i < (r); i++)
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define per(i, n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 1 << 30;  // int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
//ミョ(-ω- ?)
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> table(h + 2, vector<char>(w + 2, '#'));
    ll cnt = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> table[i + 1][j + 1];
            if (table[i + 1][j + 1] == '#') cnt++;
        }
    }
    static const int dx[] = {-1, 0, 0, 1};
    static const int dy[] = {0, -1, 1, 0};
    vector<vector<int>> seen(h + 2, vector<int>(w + 2, 0));
    queue<P> que;
    que.push(make_pair(1, 1));
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int x, y;
        tie(x, y) = p;
        rep(i, 4) {
            if (seen[x + dx[i]][y + dy[i]] != 0) continue;
            if (table[x + dx[i]][y + dy[i]] == '#') continue;
            seen[x + dx[i]][y + dy[i]] = seen[x][y] + 1;
            que.push({x + dx[i], y + dy[i]});
        }
    }
    if (seen[h][w] == 0) cout << -1 << "\n";
    else cout << h * w - (seen[h][w] + 1) - cnt << "\n";
    return 0;
}