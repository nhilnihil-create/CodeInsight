#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__


vector<vi> mp = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int H, W; cin >> H >> W;
    vector<vc> G(H, vc(W));
    vector<pii> blk;
    rep(i, H) {
        rep(j, W) {
            cin >> G[i][j];
            if (G[i][j] == '#') blk.push_back(make_pair(i, j));
        }
    }

    vector<vi> route(H, vi(W, INF));
    queue<pii> q;
    for (int i = 0; i < blk.size(); i++) {
        pii bp = blk[i];
        int bx = bp.first;
        int by = bp.second;

        route[bx][by] = 0;
        for (int j = 0; j < 4; j++) {
            int nx = bx + mp[j][0];
            int ny = by + mp[j][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && G[nx][ny] != '#') {
                route[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int ux = p.first, uy = p.second;
        if (G[ux][uy] == '#') continue;
        G[ux][uy] = '#';

        for (int j = 0; j < 4; j++) {
            int vx = ux + mp[j][0];
            int vy = uy + mp[j][1];

            if (vx >= 0 && vx < H && vy >= 0 && vy < W && G[vx][vy] != '#') {
                route[vx][vy] = min(route[vx][vy], route[ux][uy] + 1);
                q.push(make_pair(vx, vy));
            }
        }
    }

    int cnt = -1;
    rep(i, H) {
        rep(j, W) {
            cnt = max(cnt, route[i][j]);
        }
    }

    cout << cnt << endl;
}
