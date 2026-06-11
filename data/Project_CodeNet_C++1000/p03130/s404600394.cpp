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
    vector<ll> check(4);
    rep(i, 3) {
        ll a, b;
        cin >> a >> b;
        check[--a]++;
        check[--b]++;
    }

    sort(check.begin(), check.end());
    if (check[0] == 1 && check[1] == 1 && check[2] == 2 && check[3] == 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}