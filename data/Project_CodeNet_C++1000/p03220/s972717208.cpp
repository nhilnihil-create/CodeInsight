#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll N, T, A;
    cin >> N >> T >> A;

    double diff = numeric_limits<double>::max();
    ll index    = 0;
    REP(i, N) {
        ll t;
        cin >> t;
        auto temperature = T - 0.006 * t;

        auto d = abs(A - temperature);
        if (diff > d) {
            diff  = d;
            index = i;
        }
    }

    cout << index + 1 << endl;
    return 0;
}