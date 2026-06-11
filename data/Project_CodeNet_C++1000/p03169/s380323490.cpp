#include <bits/stdc++.h>

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif

//{{{
using namespace std;
typedef long long LL;
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
// clang-format off
#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr<<endl;}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while
(getline(ss, x, c)) v.push_back(x); return v;} void err(vector<string>::iterator) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}
// clang-format on
//}}}

const int N = 301;
const int mod = 1e9 + 7;

double dp[N][N][N];
int n;
int cnt[4];

double dfs(int a, int b, int c)
{
    // if (a > n || b > n || c > n) return 0;
    if (dp[a][b][c] >= 0) return dp[a][b][c];
    double s = a + b + c;
    double ret = n / s;

    if (a > 0) ret += dfs(a - 1, b, c) * a / s;
    if (b > 0) ret += dfs(a + 1, b - 1, c) * b / s;
    if (c > 0) ret += dfs(a, b + 1, c - 1) * c / s;
    return dp[a][b][c] = ret;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif

    while (~scanf("%d", &n))
    {
        clr(cnt, 0);
        for (int i = 1; i <= n; i++)
        {
            int v;
            scanf("%d", &v);
            cnt[v]++;
        }

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= n; k++) dp[i][j][k] = -1;

        dp[0][0][0] = 0;
        double ans = dfs(cnt[1], cnt[2], cnt[3]);
        printf("%.10lf\n", ans);
    }

    return 0;
}
