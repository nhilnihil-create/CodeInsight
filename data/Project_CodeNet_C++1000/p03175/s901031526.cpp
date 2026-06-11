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

const int mod = 1e9 + 7;
struct E
{
    int v, next;
} edge[N << 1];
int head[N], e;
void addedge(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

int dp[N][2];

int dfs(int u, int f)
{
    int son = 0;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == f) continue;
        son += dfs(v, u);
    }

    if (son == 0)
    {
        dp[u][0] = 1;
        dp[u][1] = 1;
        return 1;
    }

    LL v0 = 1;
    LL vall = 1;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == f) continue;
        v0 = v0 * dp[v][0] % mod;
        vall = vall * (dp[v][0] + dp[v][1]) % mod;
    }
    dp[u][0] = vall;
    dp[u][1] = v0;
    return son + 1;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        clr(head, -1), e = 0;
        int u, v;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1, -1);
        LL ans = (dp[1][0] + dp[1][1]) % mod;
        cout << ans << endl;
    }

    return 0;
}
