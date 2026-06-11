#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int h, w;
string s[55];
int dist[55][55];

int main() {
    cin >> h >> w;
    rep(i, h) cin >> s[i];

    rep(i, h) rep(j, w) dist[i][j] = INF;
    dist[0][0] = 0;
    queue<pii> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        int y = now.first, x = now.second;
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (s[ny][nx] == '#') continue;
            if (chmin(dist[ny][nx], dist[y][x] + 1)) {
                q.emplace(ny, nx);
            }
        }
    }

    if (dist[h-1][w-1] == INF) {
        cout << -1 << endl;
        return 0;
    }

    int black = 0;
    rep(i, h) rep(j, w) {
        if (s[i][j] == '#') black++;
    }

    cout << h*w - black - dist[h-1][w-1] - 1 << endl;
}
