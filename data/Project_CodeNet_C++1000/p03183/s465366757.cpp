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

const int N = 1e5 + 10;
int T;
int n;

struct I
{
    LL w, s, v;
} item[1010];

bool cmp(const I& a, const I& b) { return a.s + a.w < b.s + b.w; }

LL dp[20010];

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> item[i].w >> item[i].s >> item[i].v;
        }
        sort(item + 1, item + 1 + n, cmp);

        clr(dp, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            LL w = item[i + 1].w;
            LL s = item[i + 1].s;
            LL v = item[i + 1].v;

            for (int j = 20000; j >= 0; j--)
            {
                if (dp[j] == -1) continue;
                if (j + w > 20000) continue;

                if (s >= j)
                {
                    dp[j + w] = max(dp[j + w], dp[j] + v);
                }
            }
        }
        LL ans = 0;
        for (int i = 0; i <= 20000; i++)
        {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
