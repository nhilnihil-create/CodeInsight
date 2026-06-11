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
const int MAX = 3001;
const int MOD = 1e9 + 7;
int n, m;
double memo[MAX][MAX];
bool vis[MAX][MAX];
void read();
void solve();
void clear();
double dp(int i, int j);
double arr[MAX];
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
    cin >> n;
    lp(i, n)
    {
        cin >> arr[i];
    }
}

void solve()
{
    read();
    double p = dp(0, 0);
    cout << setprecision(10) << fixed;
    cout << p << '\n';
}
double dp(int i, int j)
{
    if (i == n)
        return (2 * j >= n ? 1.0 : 0.0);
    double &ret = memo[i][j];
    if (vis[i][j])
        return ret;
    vis[i][j] = 1;
    double path = 0.0;
    double path2 = 0.0;
    path = arr[i] * dp(i + 1, j + 1);
    path2 = (1.0 - arr[i]) * dp(i + 1, j);
    return ret = path + path2;
}