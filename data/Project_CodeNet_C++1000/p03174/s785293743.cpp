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
int T;

const int mod = 1e9 + 7;
int dp[22][1 << 21];
int a[22][22];
int n;

//生成下个相同1的数
int nextN(int n)
{
    int x = n & (-n);
    int t = n + x;
    return ((n ^ t) / x) >> 2 | t;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        clr(dp, 0);
        int lim = (1 << n);
        for (int j = 0; j < n; j++)
        {
            if (a[0][j] == 1)
            {
                dp[0][1 << j] = 1;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int st = (1 << (i + 1)) - 1; st < lim; st = nextN(st))
            {
                // debug(i, st);
                for (int j = 0; j < n; j++)
                {
                    if (a[i + 1][j] == 0) continue;
                    if (st & (1 << j)) continue;
                    dp[i + 1][st | (1 << j)] += dp[i][st];
                    dp[i + 1][st | (1 << j)] %= mod;
                }
            }
        }

        cout << dp[n - 1][lim - 1] << endl;
    }

    return 0;
}
