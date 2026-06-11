#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> mp(h, vector<char>(w));
    int bc = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> mp[i][j];
            if (mp[i][j] == '#') ++bc;
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, -1));
    queue<pair<int, int>> q;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    q.push({0,0});
    dp[0][0] = 0;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first; int y = p.second;
        rep(i, 4) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w && mp[nx][ny] == '.' && dp[nx][ny] == -1) {
                dp[nx][ny] = dp[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    int rt = dp[h-1][w-1];
    int ret = (rt == -1) ? -1 : h*w - rt - bc -1;
    cout << ret << endl;
    return 0;
}