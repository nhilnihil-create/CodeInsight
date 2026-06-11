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
    ll a, b, k;
    cin >> a >> b >> k;
    if (b - a + 1 <= 2 * k) {
        for (ll i = a; i <= b; i++) {
            cout << i << "\n";
        }
    } else {
        for (ll i = a; i <= a + k - 1; i++) {
            cout << i << "\n";
        }
        for (ll i = b - k + 1; i <= b; i++) {
            cout << i << "\n";
        }
    }
    return 0;
}