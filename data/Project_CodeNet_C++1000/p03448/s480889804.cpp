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
    ll A, B, C, X;
    cin >> A >> B >> C >> X;

    ll count = 0;
    for (ll a = 0; a <= A; ++a) {
        for (ll b = 0; b <= B; ++b) {
            ll x = X - (a * 500 + b * 100);
            if (x >= 0 && (x % 50) == 0 && x / 50 <= C) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}