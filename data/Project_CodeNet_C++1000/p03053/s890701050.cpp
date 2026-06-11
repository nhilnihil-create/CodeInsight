#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define mp make_pair
#define fi first
#define se second
const int N = 1e3 + 5;
const int INF = INT_MAX;

int n, m, x, y, z, ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int val[N][N];
char cell[N][N];
iii a;
queue<iii> q;

bool inside(int i) {
    return (x + dx[i] >= 1 && x + dx[i] <= n &&
            y + dy[i] >= 1 && y + dy[i] <= m);
}

void BFS() {
    while(!q.empty()) {
        a = q.front();
        x = a.fi.fi, y = a.fi.se, z = a.se;
        q.pop();
        if(val[x][y] > -1) continue;
        val[x][y] = z;
        for(int i = 0; i < 4; i++) {
            if(!inside(i)) continue;
            q.push(mp(mp(x + dx[i], y + dy[i]), z + 1));
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> cell[i][j];
            if(cell[i][j] == '#') q.push(mp(mp(i, j), 0));
        }
    }
    BFS();
    ans = -INF;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans = max(ans, val[i][j]);
        }
    }
    cout << ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(val, -1, sizeof(val));
    solve();

}