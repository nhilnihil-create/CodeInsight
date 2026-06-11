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

    queue<P> q;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    auto update = [&](int y, int x, int v) {
        if(dist[y][x] != INF) return;
        dist[y][x] = v;
        q.push(P(y, x));
    };
    rep(i, h) {
        rep(j, w) {
            if(field[i][j] == '#') update(i, j, 0);
        }
    }
    while(!q.empty()) {
        int ny = q.front().first, nx = q.front().second;
        q.pop();
        rep(i, 4) {
            int nj = ny + dy[i], ni = nx + dx[i];
            if(nj >= h || nj < 0 || ni >= w || ni < 0) continue;
            if(field[nj][ni] == '#') continue;
            update(nj, ni, dist[ny][nx] + 1);
        }
    }
    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(dist[i][j] == INF) continue;
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}