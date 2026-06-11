#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> s(H);

    rep(i, H) cin >> s[i];

    vector<vector<int>> dis(H, vector<int>(W, -1));
    queue<P> que;
    que.push({0, 0});
    dis[0][0] = 0;
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        if (x == W - 1 && y == H - 1) break;
        rep(i, 4) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (tx >= W || tx < 0 || ty >= H || ty < 0 || s[ty][tx] == '#' || dis[ty][tx] != -1) continue;
            dis[ty][tx] = dis[y][x] + 1;
            que.push({tx, ty});
        }
    }

    int b = 0;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '#') b++;
        }
    }

    int ans = H * W - b - 1;
    if (dis[H - 1][W - 1] == -1) ans = -1;
    else ans -= dis[H - 1][W - 1];
    cout << ans << endl;
    return 0;
}