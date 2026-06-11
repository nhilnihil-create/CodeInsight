#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1e9 + 7;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo \
    { no return; }

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template <typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false) {
    vector<T> a = vector<T>(n + oneIndexed);

    for (ll i = 0; i < n; i++) {
        T p;
        cin >> p;
        a[i + oneIndexed] = p;
    }

    return move(a);
}

template <typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    // [pos][dig at this posn]
    vv dp(n + 1, v(n + 1, 0));
    dp[1][1] = 1;

    for (ll pos = 2; pos <= n; pos++) {
        char sign = s[pos - 2];

        ll s1 = 0;
        ll s2 = 0;

        for (ll dig = 1; dig <= n; dig++) {
            s2 += dp[pos - 1][dig];
        }

        s2 %= MOD;

        for (ll dig = 1; dig <= pos; dig++) {
            switch (sign) {
                case '<':
                    if (dig > 1)
                        dp[pos][dig] += s1;
                    break;
                case '>':
                    if (dig < pos)
                        dp[pos][dig] += s2;
                    break;
            }

            s1 += dp[pos - 1][dig];
            s2 -= dp[pos - 1][dig];
            s2 += MOD;

            s1 %= MOD;
            s2 %= MOD;

            dp[pos][dig] %= MOD;
        }
    }

    ll x = 0;
    for (ll i = 1; i <= n; i++) {
        x += dp[n][i];
    }
    x %= MOD;
    cout << x;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file", "r", stdin);
    // freopen("file", "w", stdout);

    solve();
    return 0;
}