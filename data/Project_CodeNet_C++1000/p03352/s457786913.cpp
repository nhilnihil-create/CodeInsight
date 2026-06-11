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
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll x;
    cin >> x;
    if (x <= 3) {
        cout << 1 << "\n";
        return 0;
    }

    ll ans = 0;
    rep(i, x + 1) {
        if (i == 0) continue;
        ll ins = i, cnt = 0;
        rep(j, x + 1) {
            if (j == 0 || j == 1) continue;

            while (ins % j == 0) {
                cnt++;
                ins /= j;
            }

            if (ins != 1) {
                ins = i;
                cnt = 0;
                continue;
            }
            if (cnt < 2) {
                ins = i;
                cnt = 0;
                continue;
            }

            ans = i;
            ins = i;
            cnt = 0;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}