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

int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans;

    if (k >= a && b - 1 > a) {
        k -= (a - 1);
        ans = a + k / 2 * (b - a) + (k % 2);
        cout << ans << "\n";
    } else {
        cout << k + 1 << "\n";
    }

    return 0;
}