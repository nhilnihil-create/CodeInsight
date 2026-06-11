#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

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

    int N;
    cin >> N;
    vector<int> L(N), R(N);
    rep(i, N) {
        cin >> L[i] >> R[i];
        L[i] *= 2;
        R[i] *= -2;
    }
    sort(ALL(L), greater<int>());
    sort(ALL(R), greater<int>());
    vector<ll> sumL(N + 1), sumR(N + 1);
    rep(i, N) {
        sumL[i + 1] = sumL[i] + L[i];
        sumR[i + 1] = sumR[i] + R[i];
    }
    ll ans = 0;
    FOR(i, 1, N + 1) {
        chmax(ans, sumL[i] + sumR[i]);
        chmax(ans, sumL[i] + sumR[i - 1]);
        chmax(ans, sumL[i - 1] + sumR[i]);
    }
    cout << ans << endl;

    return 0;
}