#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> II;
typedef pair<long long, int> LLI;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<II> VII;

#define For(i,a,b) for(int i = a;i <= b; i++)
#define Rep(i,a,b) for(int i = a;i >= b; i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(auto i : f)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define BUG(x) (cerr << #x << " = " << x << "\n")
#define ARRAY(f) {cerr << #f << " = "; FOR(i, f) cout << i << ' '; cout << "\n";}
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define bit(x, i) ((x >> (i)) & 1LL)
#define onbit(x, i) (x | (1LL << (i)))
#define offbit(x, i) (x & ~(1 << (i)))

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, a[N], inv[N], ps[N], fact;

int mul(int a, int b)
{
    return LL(a)*b % MOD;
}

int add(int a, int b)
{
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
    return a;
}

int pw(int a, int n)
{
    int ans = 1;
    for (; n; n >>= 1)
    {
        if (n & 1) ans = mul(ans, a);
        a = mul(a, a);
    }
    return ans;
}

void init()
{
    fact = 1;
    For(i, 1, n)
    {
        inv[i] = pw(i, MOD-2);
        ps[i] = add(ps[i-1], inv[i]);
        fact = mul(fact, i);
    }
}

void solve()
{
    int res = 0;
    //cerr << n << "\n";
    For(i, 1, n)
    {
        int t = add(ps[i], ps[n-i+1]-ps[1]);
        //For(j, 1, n) t = add(t, inv[abs(i-j)+1]);
        //cerr << i << ' ' << t << "\n";
        res = add(res, mul(a[i], t));
    }
    res = mul(res, fact);
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
       // freopen("in.txt","r",stdin);
        //freopen("","w",stdout);
    #endif
    cin >> n;
    //cerr << n << "\n";
    For(i, 1, n) cin >> a[i];
    init();
    solve();
}
