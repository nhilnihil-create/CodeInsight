#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n, mn = inf, sum = 0;

    cin >> n;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        sum += a;
        if(a > b) chmin(mn, b);
    }

    cout << max(0LL, sum - mn) << endl;

    return 0;
}