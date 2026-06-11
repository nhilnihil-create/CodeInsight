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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    vector<bool> exi(26, false);
    rep(i, n - 1) {
        ll cnt = 0;
        for (ll j = 0; j <= i; j++) {
            exi[(ll)(s[j] - 'a')] = true;
        }
        for (ll j = i + 1; j < n; j++) {
            if (exi[(ll)(s[j] - 'a')] == true) {
                cnt++;
                exi[(ll)(s[j] - 'a')] = false;
            }
        }
        chmax(ans, cnt);
    }

    cout << ans << "\n";
    return 0;
}