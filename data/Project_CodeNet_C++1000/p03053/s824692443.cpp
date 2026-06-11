#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

P dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int H, W; cin >> H >> W;
    char s[H][W];
    queue<P> Q;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    rep(i, H) {
        rep(j, W) {
            cin >> s[i][j];
            if(s[i][j] == '#') {
                Q.push(mp(i, j));
                dist[i][j] = 0;
            }
        }
    }
    while(!Q.empty()) {
        P q = Q.front(); Q.pop();
        rep(i, 4) {
            int h = q.first + dir[i].first, w = q.second + dir[i].second;
            if(h < 0 || h >= H || w < 0 || w >= W) continue;
            if(s[h][w] == '#') continue;
            if(dist[h][w] == INF) {
                Q.push(mp(h, w));
                dist[h][w] = dist[q.first][q.second] + 1;
            }
            dist[h][w] = min(dist[h][w], dist[q.first][q.second] + 1);
        }
    }
    int ans = 0;
    rep(i, H) {
        rep(j, W) {
            if(s[i][j] == '#')continue;
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << endl;
}
