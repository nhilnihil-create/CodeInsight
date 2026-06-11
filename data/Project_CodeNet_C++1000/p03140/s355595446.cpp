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
    ll n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;

    vector<ll> check(n, 0);
    rep(i, n) {
        if (a[i] == b[i] && b[i] == c[i])
            check[i] = 0;
        else if (a[i] == b[i] || b[i] == c[i] || a[i] == c[i])
            check[i] = 1;
        else
            check[i] = 2;
    }

    ll ans = 0;
    rep(i, n) {
        ans += check[i];
        // cout << check[i] << " ";
    }
    cout << endl;
    cout << ans << "\n";
    return 0;
}