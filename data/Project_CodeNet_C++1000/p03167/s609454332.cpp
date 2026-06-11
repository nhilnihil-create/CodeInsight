#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define INF 1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define LSOne(S) (S & (-S))
#define PI acos(-1.0)
#define P(x) cout << #x << " = { " << x << " }\n"
#define tests()  \
    int tttt;    \
    cin >> tttt; \
    while (tttt--)
#define fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define file_IO                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
typedef long long ll;
int dcmp(long double x, long double y)
{
    return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
const int MAX = 1e3 + 10;
const int MOD = 1e9 + 7;
int n, m;
int memo[MAX][MAX];
bool vis[MAX];
string grid[MAX];
void read();
void solve();
void clear();
int dp(int i, int j);
int main()
{
#ifndef ONLINE_JUDGE
    file_IO;
#else
    fast_IO;
#endif

    solve();
}
void read()
{
    cin >> n >> m;
    lp(i, n) { cin >> grid[i]; }
}
void clear()
{
    clr(memo, -1);
}
void solve()
{
    read();
    //clear();
    //   cout << dp(0, 0) << '\n';
    memo[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (grid[i][j] != '#')
            {
                if (i + 1 < n)
                    memo[i][j] += memo[i + 1][j] % MOD;
                if (j + 1 < m)
                    memo[i][j] += memo[i][j + 1] % MOD;
                memo[i][j] %= MOD;
            }
        }
    }
    cout << memo[0][0] % MOD << '\n';
}
int dp(int i, int j)
{
    if (i == n - 1 && j == m - 1)
        return 1;
    int &ret = memo[i][j];
    if (ret != -1)
        return ret;
    int path = 0;
    int path2 = 0;
    if (i + 1 < n && grid[i + 1][j] != '#')
        path = dp(i + 1, j);
    if (j + 1 < m && grid[i][j + 1] != '#')
        path2 = dp(i, j + 1);

    return ret = (path2 % MOD + path % MOD) % MOD;
}