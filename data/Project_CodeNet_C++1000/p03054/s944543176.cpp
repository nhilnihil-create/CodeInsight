const int LG = 21;
const int FN = 400005;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return inq(x, MOD - 2);
}

bool __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

void __precompute_combinatorics()
{
    __precomputed_combinatorics = 1;
    __fact.resize(FN);
    __ufact.resize(FN);
    __rev.resize(FN);
    __rev[1] = 1;
    for (int i = 2; i < FN; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < FN; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n) return 0;
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

const int N = 430000;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w, n, x, y;
    cin >> h >> w >> n;
    cin >> x >> y;
    string a, b;
    cin >> a >> b;
    int left_moves = y;
    int right_moves = w - y + 1;
    int up_moves = x;
    int down_moves = h - x + 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'L') left_moves--;
        if (left_moves == 0) cout << "NO", exit(0);
        if (b[i] == 'R') left_moves++; left_moves = min(left_moves, w);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'R') right_moves--;
        if (right_moves == 0) cout << "NO", exit(0);
        if (b[i] == 'L') right_moves++; right_moves = min(right_moves, w);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'D') down_moves--;
        if (down_moves == 0) cout << "NO", exit(0);
        if (b[i] == 'U') down_moves++; down_moves = min(down_moves, h);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'U') up_moves--;
        if (up_moves == 0) cout << "NO", exit(0);
        if (b[i] == 'D') up_moves++; up_moves = min(up_moves, h);
    }
    cout << "YES";
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/
