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

const int N = 3000 + 10;
const int mod = 1e9 + 7;

int n;
char ss[N];
LL dp[N][N];

LL s[N];

LL cal(int st, int ed)
{
    if (st > ed) return 0;
    LL ret = s[ed];
    if (st >= 1) ret -= s[st - 1];
    if (ret < 0) ret = (ret + mod) % mod;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif

    while (~scanf("%d", &n))
    {
        scanf("%s", ss + 1);

        clr(dp, 0);
        dp[1][1] = 1;

        s[0] = 0;
        s[1] = 1;
        s[2] = 1;

        for (int i = 2; i <= n; i++)
        {
            char op = ss[i - 1];

            for (int j = 1; j <= i; j++)
            {
                if (op == '<')
                {
                    LL v = cal(1, j - 1);
                    dp[i][j] = v;
                    // for (int k = 1; k < j; k++)
                    //{
                    // dp[i][j] += dp[i - 1][k];
                    // dp[i][j] %= mod;
                    //}
                }
                else
                {
                    LL v = cal(j, i);

                    dp[i][j] = v;
                    // for (int k = j; k <= i; k++)
                    //{
                    // dp[i][j] += dp[i - 1][k];
                    // dp[i][j] %= mod;
                    //}
                }
            }

            for (int j = 1; j <= i + 1; j++) s[j] = (s[j - 1] + dp[i][j]) % mod;
        }

        LL ans = 0;
        for (int i = 1; i <= n; i++) ans = (ans + dp[n][i]) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}
