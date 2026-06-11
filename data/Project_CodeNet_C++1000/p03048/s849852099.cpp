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
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for (ll r = 0; r <= N; r++) {
        for (ll g = 0; g <= N; g++) {
            if (N - r * R - g * G >= 0 && (N - r * R - g * G) % B == 0) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}