/*
    [Gnana Deepak]
    [August 03, 2020 6:01 PM]
    [M - Candies]
    [https://atcoder.jp/contests/dp/tasks/dp_m]
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

// Everything till line 152 is taken from "https://codeforces.com/contest/997/submission/88692369 and made few changes"
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
    cout << "\ncompleted debug\n";
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
const int N = 100;
const int K = 1e5;
int DP[K + 1];
int Arr[N + 1];
const int mod = mod1;
// -- variables and consts --

void add_self(int &a, int b)
{
    a += b;
    if (a >= mod)
    {
        a -= mod;
    }
}

void sub_self(int &a, int b)
{
    a -= b;
    if (a < 0)
    {
        a += mod;
    }
}

void accio_ac(void)
{
    int n, k;
    cin >> n >> k;
    fori(i, 1, n)
    {
        cin >> Arr[i];
    }
    DP[0] = 1;
    fori(child, 1, n)
    {
        int choco = Arr[child];
        v(int) fake(k + 1, 0);
        rofi(used, k, 0)
        {
            int add_here = DP[used];
            int left = used + 1;
            int right = min(used + choco, k);
            if (left <= right)
            {
                add_self(fake[left], add_here);
                if (right + 1 <= k)
                {
                    sub_self(fake[right + 1], add_here);
                }
            }
        }
        int prefix_sum = 0;
        fori(i, 0, k)
        {
            add_self(prefix_sum, fake[i]);
            add_self(DP[i], prefix_sum);
        }
    }
    cout << DP[k] << endl;
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
