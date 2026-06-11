#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

vs grid;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    
    grid = vs(h);
    rep(i, h) cin >> grid[i];

    queue<P> q;
    vvi d(h, vi(w, -1));
    rep(i, h) rep(j, w) {
        if (grid[i][j] == '#') {
            q.push(P(i, j));
            d[i][j] = 0;
        }
    }
    while (!q.empty()) {
        int y = q.front().fi, x = q.front().se;
        q.pop();
        rep(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
            if (d[ny][nx] != -1) continue;
            d[ny][nx] = d[y][x] + 1;
            q.push(P(ny, nx));
        }
    }
    int mx = 0;
    rep(i, h) rep(j, w) chmax(mx, d[i][j]);
    cout << mx << endl;
}