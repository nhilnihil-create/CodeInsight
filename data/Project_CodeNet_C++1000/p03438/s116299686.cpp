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

    int n;
    cin >> n;
    ll a[n], sum = 0, A = 0, B = 0;
    rep(i, n) cin >> a[i], sum -= a[i];
    rep(i, n) {
        ll b;
        cin >> b;
        sum += b;
        if(b < a[i])
            B += a[i] - b;
        else
            A += b - a[i] + 1 >> 1;
    }
    cout << (sum >= A && sum >= B ? "Yes" : "No") << endl;

    return 0;
}