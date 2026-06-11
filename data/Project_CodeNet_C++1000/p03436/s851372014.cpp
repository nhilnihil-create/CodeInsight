#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int h, w;
int b_num, w_num;

bool seen[59][59];
int dist[59][59], M[59][59];
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

void bfs(int sx, int sy) {
    queue<pair<int, int>> qu;
    qu.push(make_pair(sx, sy));
    seen[sy][sx] = true;
    while (!qu.empty()) {
        int ux = qu.front().first, uy = qu.front().second;
        qu.pop();
        rep(i, 4) {
            int nx = ux + dx[i], ny = uy + dy[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (!seen[ny][nx] && M[ny][nx] == 0) {
                    seen[ny][nx] = true;
                    dist[ny][nx] = dist[uy][ux] + 1;
                    qu.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    cin >> h >> w;
    rep(y, h) rep(x, w) {
        char c;
        cin >> c;
        if (c == '.') {
            w_num++;
        } else {
            b_num++;
            M[y][x]++;
        }
    }
    bfs(0, 0);
    if (dist[h - 1][w - 1] == 0)
        cout << -1 << endl;
    else
        cout << (h * w - b_num - dist[h - 1][w - 1] - 1) << endl;
    return 0;
}