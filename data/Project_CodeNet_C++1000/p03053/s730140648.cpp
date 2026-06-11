#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int h, w;
vector<string> s;
int d[1001][1001];
queue<P> q;

void bfs()
{
    while(!q.empty())
    {
        P p = q.front(); q.pop();
        rep(i, 4)
        {
            int x = p.first + dx[i], y = p.second + dy[i];
            if (x >= 0 && x < w && y >= 0 && y < h && s[y][x] != '#'
            && d[x][y] == -1)
            {
                q.push(P(x, y));
                d[x][y] = d[p.first][p.second] + 1;
            }
        }
    }
}
int main()
{
    cin >> h >> w;
    s.resize(h);
    rep(i, h) cin >> s[i];

    rep(i, w)
        rep(j, h) d[i][j] = -1;

    rep(i, h)
    {
        rep(j, w)
            if(s[i][j] == '#')
            {
                d[j][i] = 0;
                q.push(P(j, i));
            }
    }
    bfs();
    int ans = 0;
    rep(i, w)
        rep(j, h) ans = max(ans, d[i][j]);
    cout << ans << endl;
}