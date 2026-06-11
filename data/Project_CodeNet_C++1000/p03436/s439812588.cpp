#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    rep(i, h) cin >> field[i];
    int sy = 0, sx = 0, gy = h - 1, gx = w - 1;

    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<P> q;
    auto update = [&](int y, int x, int v) {
        if(dist[y][x] != INF) return;
        dist[y][x] = v;
        q.push(P(y, x));
    };
    update(sy, sx, 0);
    while(!q.empty()) {
        int ny = q.front().first, nx = q.front().second;
        q.pop();
        rep(dir, 4) {
            int nj = ny + dy[dir], ni = nx + dx[dir];
            if(nj >= h || nj < 0 || ni >= w || ni < 0) continue;
            if(field[nj][ni] == '#') continue;
            update(nj, ni, dist[ny][nx] + 1);
        }
    }
    int maxv = dist[gy][gx];
    if(maxv == INF) {
        cout << -1 << endl;
        return 0;
    }
    
    int tot = 0;
    rep(i, h) {
        rep(j, w) {
            if(field[i][j] == '.') tot++;
        }
    }
    int ans = tot - (maxv + 1);
    cout << ans << endl;

    return 0;
}