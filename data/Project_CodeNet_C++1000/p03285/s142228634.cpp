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
    ll N;
    cin >> N;

    const ll MAX = 100;

    bool isFind;

    for (ll i = 0; i <= MAX; i += 4) {
        ll v = N - i;
        if (v < 0) break;
        isFind |= v % 7 == 0;
        if (isFind) break;
    }

    cout << (isFind ? "Yes" : "No") << endl;

    return 0;
}