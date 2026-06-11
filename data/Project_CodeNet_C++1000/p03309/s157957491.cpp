#include <bits/stdc++.h>

//{{{
#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL, int> pii;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
// clang-format off
#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr<<endl;}
 vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x;
 while (getline(ss, x, c)) v.push_back(x); return v;} void err(vector<string>::iterator) {}
 template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}
// clang-format on
//}}}
//

int T;

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n;
int a[N];

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] -= (i + 1);
        }
        sort(a, a + n);
        int v = a[n / 2];
        LL ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(v - a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}