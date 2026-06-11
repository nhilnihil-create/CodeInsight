#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> field(H, vector<char>(W));
    int bcnt = 0;
    rep(i, H) rep(j, W) {
        cin >> field[i][j];
        if(field[i][j] == '#')
            bcnt++;
    }
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int, pii>> que;
    que.push(MP(0, MP(0, 0)));
    dist[0][0] = 0;
    while(!que.empty()) {
        auto p = que.front();
        que.pop();
        int d = p.first;
        int x = p.second.first;
        int y = p.second.second;
        rep(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < W && ny >= 0 && ny < H && field[ny][nx] == '.') {
                que.push(MP(d + 1, MP(nx, ny)));
                dist[ny][nx] = d + 1;
                field[ny][nx] = '#';
            }
        }
    }
    if(dist[H - 1][W - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << H * W - bcnt - dist[H - 1][W - 1] - 1 << endl;
    }
    return 0;
}