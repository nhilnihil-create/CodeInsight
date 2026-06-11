#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    auto g2 = g;

    rep(i, h) rep(j, w) {
        if (g[i][j] == '#') continue;
        int cnt = 0;

        rep(k, 8) {
            int y = i + dy[k];
            int x = j + dx[k];
            if (y >= 0 && y < h && x >= 0 && x < w) {
                if (g[y][x] == '#') cnt++;
            }
        }

        g2[i][j] = '0'+cnt;
    }

    rep(i, h) cout << g2[i] << endl;
    return 0;
}