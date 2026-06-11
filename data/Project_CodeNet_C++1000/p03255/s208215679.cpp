#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll N, X;
    cin >> N >> X;
    vector<ll> x(N + 1);
    rep(i, N) cin >> x[N - i];
    rep(i, N) x[i + 1] += x[i];
    ll ans = inf;
    FOR(k, 1, N + 1) {
        ll cost = (N + k) * X;
        for(ll i = 0; i * k < N; i++) {
            cost += (x[min((i + 1) * k, N)] - x[i * k]) * max(2 * i + 3, 5LL);
            if(cost >= ans) break;
        }
        chmin(ans, cost);
    }

    cout << ans << endl;

    return 0;
}