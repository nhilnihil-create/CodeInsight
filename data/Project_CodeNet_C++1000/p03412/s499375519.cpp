#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    V<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, 30) {
        V<ll> A(n);
        ll t = 1 << i;
        rep(j, n) A[j] = a[j] & 2 * t - 1;
        sort(ALL(A));
        ll cnt = 0;
        rep(j, n) {
            ll B = b[j] & 2 * t - 1;
            cnt += lower_bound(ALL(A), 2 * t - B) - lower_bound(ALL(A), t - B);
            cnt +=
                lower_bound(ALL(A), 4 * t - B) - lower_bound(ALL(A), 3 * t - B);
        }
        ans += (cnt & 1) << i;
    }
    cout << ans << endl;

    return 0;
}