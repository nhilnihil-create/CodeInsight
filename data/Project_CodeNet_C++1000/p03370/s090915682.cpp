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
    ll N, X;
    cin >> N >> X;

    vector<ll> donut(N);
    ll minValue = INF;
    REP(i, N) {
        cin >> donut[i];
        chmin(minValue, donut[i]);
        X -= donut[i];
    }

    cout << N + X / minValue << endl;

    return 0;
}