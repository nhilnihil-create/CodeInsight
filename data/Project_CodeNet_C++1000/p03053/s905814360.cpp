#include "bits/stdc++.h"

using namespace std;

#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

int n, m;
bool ok(int r, int c){
    return ~r && ~c && r < n && c < m;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int white = 0; cin >> n >> m;

    char a[n][m];

    bool vis[n][m] = {};

    int dis[n][m] = {};
    clr(dis, -1);

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == '.') white++;
            else q.push({i, j}), vis[i][j] = 1, dis[i][j] = 0;
        }
    }

    if(!white) return cout << 0, 0;

    while(q.size()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = r + dx[i], y = c + dy[i];
            if(ok(x, y) && dis[x][y] == -1 && a[x][y] == '.')
                q.push({x, y}), a[x][y] = '#', dis[x][y] = 1 + dis[r][c];
        }
    }

    int mx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <m; j++)
            mx = max(mx, dis[i][j]);

    cout << mx;
    return 0;
}
