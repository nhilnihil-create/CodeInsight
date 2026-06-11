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
    vector<pair<ll, P>> ab(n);
    ll sum = 0, sum2 = 0;
    rep(i, n) {
        cin >> ab[i].se.fi;
        sum += ab[i].se.fi;
    }
    rep(i, n) {
        cin >> ab[i].se.se;
        sum2 += ab[i].se.se;
        ab[i].fi = ab[i].se.fi - ab[i].se.se;  //足りない分
    }

    if (sum < sum2) {
        cout << "-1\n";
        return 0;
    }

    sort(ab.begin(), ab.end());
    ll ans = 0;
    ll want = 0;
    rep(i, n) {
        if (ab[i].fi < 0) {
            ans++;
            want += -1 * ab[i].fi;
        }
    }
    for (ll i = n - 1; i >= 0; i--) {
        if (want > 0) {
            ans++;
            want -= ab[i].fi;
        }
    }

    cout << ans << "\n";
    return 0;
}