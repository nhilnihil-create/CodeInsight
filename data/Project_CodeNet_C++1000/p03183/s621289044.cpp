// template {{{
#include <bits/stdc++.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define sz(c) (static_cast<int>(c.size()))
#define endl "\n"

using ld = long double;
using ll = long long;

template <typename T, typename Z> inline T power(T base, Z exponent)
{
    T ret = 1;
    for (; exponent > 0; exponent >>= 1, base *= base)
        if (exponent & 1) ret *= base;
    return ret;
}
template <typename Z> Z gcd(const Z& a, const Z& b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <typename Z> Z extended_gcd(const Z& a, const Z& b, Z& x, Z& y)
{
    if (b == 0) return x = 1, y = 0, a;
    Z gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}
#ifdef DEBUG
template <typename... T>
void debug(T&&... args)
{
    ((cerr << args << " "), ..., (cerr << endl));
}
#else
template <typename... T> void debug(T&&... args) {}
#endif
#define vardump(...) #__VA_ARGS__":", (__VA_ARGS__)
// }}}

const ll INFL = numeric_limits<ll>::max() / 2;
const ll INF = numeric_limits<int>::max() / 2;
const ll MOD = 1e9+7;

const int N = 1e3 + 5;
const int W = 1e4 + 5;

int w[N], s[N], v[N];
int tw[N], ts[N], tv[N];
ll dp[W];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> s[i] >> v[i];
    }
    vector<int> idx, loc;
    for (int i = 0; i < n; i++) idx.push_back(i);
    for (int i = 0; i < n; i++) loc.push_back(i);
    sort(all(idx), [](int i, int j) {
        return min(s[i]-w[j], s[j]) > min(s[j]-w[i], s[i]);
    });
    for (int i = 0; i < n; i++) tw[i] = w[idx[i]], ts[i] = s[idx[i]], tv[i] = v[idx[i]];
    for (int i = 0; i < n; i++) w[i] = tw[i], s[i] = ts[i], v[i] = tv[i];
    for (int i = 0; i < n; i++) {
        debug(w[i], s[i], v[i]);
    }
    for (int j = 0; j < W; j++) dp[j] = -INFL;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < W; j++) {
            if (j-w[i] < 0) continue;
            int nw = min(j-w[i], s[i]);
            dp[nw] = max(dp[nw], dp[j] + v[i]);
            /* debug(i, dp[nw], nw); */
        }
        dp[s[i]] = max(dp[s[i]], (ll)v[i]);
        for (int j = 0; j < W; j++) {
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << endl;
}

// main {{{
int main()
{
    cin.sync_with_stdio(0); cin.tie(NULL);
    solve();
    return 0;
}
// }}}

