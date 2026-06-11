#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mypow(ll a, ll b) {
    ll ret = 1;
    while (b--) {
        ret *= a;
    }
    return ret;
}

ll keta(ll a) {
    ll ret = 0;
    while (a) {
        ret++;
        a /= 10;
    }
    return ret;
}

ll sumd(ll a) {
    ll ret = 0;
    while (a) {
        ret += a % 10;
        a /= 10;
    }
    return ret;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    rep(i, n + 1) {
        if (a <= sumd(i) && sumd(i) <= b) {
            ans += i;
        }
    }

    cout << ans << "\n";
    return 0;
}