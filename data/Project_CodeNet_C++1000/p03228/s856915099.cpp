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
    ll a, b, k;
    cin >> a >> b >> k;
    while (k) {
        if (a % 2 == 1) {
            a--;
        }
        b += (a / 2);
        a /= 2;

        k--;
        if (k == 0) break;

        if (b % 2 == 1) {
            b--;
        }
        a += (b / 2);
        b /= 2;

        k--;
    }

    cout << a << " " << b << "\n";
    return 0;
}