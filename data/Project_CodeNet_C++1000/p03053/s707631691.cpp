#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0};

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> g(H, vector<char> (W));
    vector<vector<int>> seen(H, vector<int>(W, -1));
    queue<pair<int, int>> q;
    rep(i, H) {
        rep(j, W) {
            char c; cin >> c;
            if(c == '#') {
                q.push(make_pair(i, j));
                seen[i][j] = 0;
            }
            g[i][j] = c;
        }
    }
    while(q.size()) {
        pair<int, int> now = q.front();
        q.pop();
        rep(i, 4) {
            int nh = now.first + dh[i];
            int nw = now.second + dw[i];
            if(nh < 0 || H <= nh || nw < 0 || W <= nw) continue;
            if(g[nh][nw] == '#') continue;
            if(seen[nh][nw] != -1) continue;
            seen[nh][nw] = seen[now.first][now.second] + 1;
            q.push(make_pair(nh, nw));
        }
    }
    int ans = 0;
    rep(i, H) rep(j, W) chmax(ans, seen[i][j]);
    cout << ans << endl;
}
