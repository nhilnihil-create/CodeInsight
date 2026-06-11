/*
    [Gnana Deepak]
    [August 04, 2020 5:56 PM]
    [P - Independent Set]
    [https://atcoder.jp/contests/dp/tasks/dp_p]
    [2000 ms]
    [1024 MB]
*/
#include <bits/stdc++.h>
using namespace std;

using ld = long double;
#define int long long

#define F first
#define S second
#define s(x) set<x>
#define um(x, y) unordered_map<x, y>
#define m(x, y) map<x, y>
#define p(x, y) pair<x, y>
#define v(x) vector<x>
#define min_heap(t) priority_queue<t, vector<t>, greater<t>>
#define max_heap(t) priority_queue<t>

#define eb emplace_back
#define mp make_pair
#define bs binary_search
#define lb lower_bound
#define ub upper_bound

#define all(v) v.begin(), v.end()
#define ss(v) stable_sort(all(v))
#define fori(i, a, b) for (int i = a; i <= b; i++)
#define rofi(i, a, b) for (int i = a; i >= b; --i)
#define scn(v1)        \
    for (auto &x : v1) \
        cin >> x;
#define deb(x) cout << #x << "=" << x << endl;
#define R(x) reverse(all(x));

#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define stprs(x) cout << fixed << setprecision(x);

const char nl = '\n';
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const ld PI = acos(-1);

// Everything till line 153 is taken from
// "https://codeforces.com/contest/997/submission/88692369 and made few changes"
typedef string str;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define sz(x) (int)(x).size()
#define ts to_string
str ts(char c)
{
    return str(1, c);
}
str ts(const char *s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b)
{
#ifdef LOCAL
    return b ? "true" : "false";
#else
    return ts((int)b);
#endif
}
template <class A>
str ts(complex<A> c)
{
    stringstream ss;
    ss << c;
    return ss.str();
}
str ts(vector<bool> v)
{
    str res = "{";
    F0R(i, sz(v))
    res += char('0' + v[i]);
    res += "}";
    return res;
}
template <size_t SZ>
str ts(bitset<SZ> b)
{
    str res = "";
    F0R(i, SZ)
    res += char('0' + b[i]);
    return res;
}
template <class A, class B>
str ts(pair<A, B> p);
template <class T>
str ts(T v)
{
#ifdef LOCAL
    bool fst = 1;
    str res = "{";
    for (const auto &x : v)
    {
        if (!fst)
            res += ", ";
        fst = 0;
        res += ts(x);
    }
    res += "}";
    return res;
#else
    bool fst = 1;
    str res = "";
    for (const auto &x : v)
    {
        if (!fst)
            res += " ";
        fst = 0;
        res += ts(x);
    }
    return res;

#endif
}
template <class A, class B>
str ts(pair<A, B> p)
{
#ifdef LOCAL
    return "(" + ts(p.F) + ", " + ts(p.S) + ")";
#else
    return ts(p.F) + " " + ts(p.S);
#endif
}
void debug()
{
    cout << "\n";
}
template <class H, class... T>
void debug(H h, T... t)
{
    string _h = ts(h);
    cout << _h;
    if (sizeof...(t))
        cout << "\n";
    debug(t...);
}

// variables and consts
const int N = 1e5;
const int MOD = mod1;
v(v(int)) adj;
v(v(int)) dp;
// -- variables and consts --

int dfs(v(v(int)) & adj, int cur, int par, int col)
{
    if (dp[cur][col] < 0)
    {
        dp[cur][col] = 1;
        for (int child : adj[cur])
        {
            if (child != par)
            {
                int mul = 0;
                mul = dfs(adj, child, cur, 0);
                if (col != 1)
                {
                    mul += dfs(adj, child, cur, 1);
                }
                if (mul >= MOD)
                    mul %= MOD;
                dp[cur][col] *= mul;
                if (dp[cur][col] >= MOD)
                    dp[cur][col] %= MOD;
            }
        }
    }
    return dp[cur][col];
}

void accio_ac(void)
{
    int n;
    cin >> n;
    adj = v(v(int))(n + 1);
    dp = v(v(int))(n + 1, v(int)(2, -1));
    fori(i, 2, n)
    {
        int xi, yi;
        cin >> xi >> yi;
        adj[xi].eb(yi);
        adj[yi].eb(xi);
    }
    int white = dfs(adj, 1, 0, 0);
    int black = dfs(adj, 1, 0, 1);
    cout << (white + black) % MOD << nl;
}

int32_t main(void)
{
    fastio;
    int __ = 1;
    // cin >> __;
    while (__--)
    {
        accio_ac();
    }
    return 0;
}
