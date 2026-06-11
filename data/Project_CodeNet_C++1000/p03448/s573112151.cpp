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

int main() {
    ll a, b, c, x;
    cin >> a >> b >> c >> x;
    ll ans = 0;
    rep(i, a + 1) {
        rep(j, b + 1) {
            rep(k, c + 1) {
                if (500 * i + 100 * j + 50 * k == x) ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}