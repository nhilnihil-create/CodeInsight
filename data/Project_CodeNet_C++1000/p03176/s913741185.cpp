
#include <bits/stdc++.h>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define ll long long
#define ld long double

#define pb push_back
#define ins insert
#define er erase

#define f(i, a, b) for (int i = a; i < b; ++i)
#define rf(i, a, b) for (int i = a; i >= b; --i)
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
#define cadd(a, b) a = add(a, b)
#define csub(a, b) a = sub(a, b)
#define cmul(a, b) a = mult(a, b)
#define mem(a, b) memset(a, b, sizeof(a))

#define vi vector<int>
#define vst vector<string>
#define vpii vector<pii>

#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define mxe max_element
#define mne min_element

#define srt(v) sort(all(v))
#define rsrt(v) sort(v.rbegin(), v.rend())

#define pii pair<int, int>
#define ff first
#define ss second

#define bs bitset
#define bpc(a) __builtin_popcount(a)

#define mii map<int, int>
#define umii unordered_map<int, int>

#define si set<int>
#define usi unordered_set<int>
#define spii set<pii>

#define pqi priority_queue<int>
#define pqpii priority_queue<pii>

#define dbg(a, st, end)                   \
    f(i, st, end + 1) cerr << a[i] << sp; \
    cerr << nl;
#define pnt(a, st, end)                   \
    f(i, st, end + 1) cout << a[i] << sp; \
    cout << nl;
#define dbgc(a)          \
    for (auto y : a)     \
        cerr << y << sp; \
    cerr << nl;
#define dbgm(a)                            \
    for (auto y : a)                       \
        cerr << y.ff << "," << y.ss << sp; \
    cerr << nl;

#define trace(a) cerr << a << nl;
#define trace2(a, b) cerr << a << sp << b << nl;
#define trace3(a, b, c) cerr << a << sp << b << sp << c << nl;

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*1ll * (b)) / gcd(a, b)

#define nl "\n"
#define sp " "

using namespace std;
using namespace std::chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ok order_of_key
#define fo find_by_order

//ll md = 1000000007;
ld pi = 3.141592653;
ll md = 998244353;

ll pw(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m);
        m = (m * m);
        b /= 2;
    }
    return c;
}

ll pwmd(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}

ll modinv(ll n)
{
    return pwmd(n, md - 2);
}

ll my_ceil(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    return a / b + 1;
}

ll nc2(ll n)
{
    return (1ll * n * (n - 1)) / 2;
}

ll nsum(ll n)
{
    return (1ll * n * (n + 1)) / 2;
}

int my_log(ll n, int b)
{
    ll i = 1;
    int ans = 0;
    while (1)
    {
        if (i > n / b)
            break;
        i *= b;
        ans++;
    }
    return ans;
}

inline int nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
{
    int ret = 0;
    bool f = 0;
    char ch = nc();
    while (ch > '9' || ch < '0')
        f ^= ch == '-', ch = nc();
    while (ch <= '9' && ch >= '0')
        ret = ret * 10 + ch - '0', ch = nc();
    return f ? -ret : ret;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

inline ll add(ll a, ll b) { return (((a >= md) ? a % md : a) + ((b >= md) ? b % md : b) + md) % md; }
inline ll subt(ll a, ll b) { return (a - b + md) % md; }
inline ll mult(ll a, ll b) { return (1ll * ((a >= md) ? a % md : a) * ((b >= md) ? b % md : b)) % md; }

inline int manhatten(pii p1, pii p2) { return abs(p1.ff - p2.ff) + abs(p1.ss - p2.ss); }

inline bool kthbit(ll n, int k) { return (n >> k) & 1; }
inline ll setkthbit(ll n, int k) { return n | (1ll << k); }
inline ll unsetkthbit(ll n, int k) { return n & ~(1ll << k); }
inline ll flipkthbit(ll n, int k) { return n ^ (1ll << k); }

//LET'S PLAY THE GAME!!

/*

CHECK FOR N=1, N=2, etc;
REMOVE DEBUG STATEMENTS
CHECK FOR DUPLICATES (SET -> MULTISET)
CHECK FOR OVERFLOW
CLEAR EVERYTHING BEFORE EVERY TESTCASE
DON'T MISTAKE ROOT FOR LEAF
DON'T ALWAYS IGNORE THE BRUTE FORCE SOLUTION!
IF NOTHING WORKS, READ THE PROBLEM STATEMENT AGAIN!

*/

#define int long long //UNCOMMENT IF NEEDED

const int mx = 200005;

class segTreeMax
{
public:
    int seg[4 * mx];

    segTreeMax()
    {
        mem(seg, 0);
    }

    void build(int *a, int l, int r, int idx)
    {
        if (l > r)
            return;
        if (l == r)
        {
            seg[idx] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, l, mid, idx << 1);
        build(a, mid + 1, r, (idx << 1) ^ 1);
        seg[idx] = min(seg[idx << 1], seg[(idx << 1) ^ 1]);
    }

    int getMax(int idx, int l, int r, int qs, int qe)
    {
        if (l > r || l > qe || r < qs)
            return 0;
        if (l >= qs && r <= qe)
            return seg[idx];
        int mid = l + (r - l) / 2;
        return max(getMax(idx << 1, l, mid, qs, qe), getMax((idx << 1) ^ 1, mid + 1, r, qs, qe));
    }

    void update(int i, int val, int l, int r, int idx)
    {
        //cout<<l<<sp<<r<<sp<<i<<nl;
        if (l > r || l > i || r < i)
            return;
        if (l == r)
        {
            seg[idx] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        update(i, val, l, mid, idx << 1);
        update(i, val, mid + 1, r, (idx << 1) ^ 1);
        seg[idx] = max(seg[idx << 1], seg[(idx << 1) ^ 1]);
    }
};

int32_t main()
{
    fast;

    int k, m, h, e;
    int x, q, l, r, y, n;

    string s, t, u;

    auto start = high_resolution_clock::now();

    int tcnt = 0;

    int tests = 1;
    //pre();
    //cin >> tests;

    while (tests--)
    {
        //cout << "Case #" << ++tcnt << ": ";
        cin >> n;
        segTreeMax segt;
        int h[n + 1], a[n + 1];
        f(i, 1, 1 + n) cin >> h[i];
        f(i, 1, 1 + n) cin >> a[i];
        int dp[n + 1];
        mem(dp, 0);
        f(i, 1, 1 + n)
        {
            e = a[i] + segt.getMax(1, 0, n, 0, h[i] - 1);
            if (e > dp[h[i]])
                segt.update(h[i], e - dp[h[i]], 0, n, 1), dp[h[i]] = e;
            ;
        }
        cout << segt.getMax(1, 0, n, 0, n);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: "
         << duration.count() / 1000000.0 << "seconds" << nl;
    return 0;
}

// AND THE GAME IS OVER !!