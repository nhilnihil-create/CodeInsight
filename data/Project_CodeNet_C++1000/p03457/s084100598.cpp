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

int main() {
    ll n;
    cin >> n;
    ll nowx = 0, nowy = 0, nowt = 0;
    bool ans = true;
    rep(i, n) {
        ll t, x, y;
        cin >> t >> x >> y;

        if (!((t - nowt) >= abs(x - nowx) + abs(y - nowy) &&
              ((t - nowt) - (abs(x - nowx) + abs(y - nowy))) % 2 == 0)) {
            ans = false;
        }

        nowt = t;
        nowx = x;
        nowy = y;
    }

    if (ans)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}