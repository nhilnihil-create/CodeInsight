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
    vector<ll> vec(3);
    rep(i, 3) cin >> vec[i];
    sort(vec.begin(), vec.end());

    ll ans = 0;
    if (!(vec[0] % 2 == vec[1] % 2 && vec[1] % 2 == vec[2] % 2)) {
        if ((vec[0] - vec[1]) % 2 == 0) {
            vec[0]++;
            vec[1]++;
        } else if ((vec[0] - vec[2]) % 2 == 0) {
            vec[0]++;
            vec[2]++;
        } else if ((vec[1] - vec[2]) % 2 == 0) {
            vec[1]++;
            vec[2]++;
        }
        ans++;
    }
    // rep(i, 3) { cout << vec[i] << endl; }
    sort(vec.begin(), vec.end());

    ans += (vec[2] - vec[0]) / 2;
    ans += (vec[2] - vec[1]) / 2;

    cout << ans << "\n";
    return 0;
}