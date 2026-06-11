#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    vector<ll> amounts;
    {
        ll n = min(X, Y);
        ll amount = n * C * 2;
        ll diff = X - Y;
        if (diff > 0) {
            amount += A * diff;
        } else {
            amount += B * -diff;
        }
        amounts.push_back(amount);
    }

    {
        ll n = max(X, Y);
        amounts.push_back(n * C * 2);
    }
    { amounts.push_back(A * X + B * Y); }

    sort(amounts.begin(), amounts.end());
    cout << amounts[0] << endl;
    return 0;
}