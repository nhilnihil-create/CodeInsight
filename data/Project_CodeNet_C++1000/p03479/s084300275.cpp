#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
int main() {
    ll X, Y;
    cin >> X >> Y;
    ll count = 1;
    ll value = X * 2;
    while (value <= Y) {
        count++;
        value *= 2;
    }
    cout << count << "\n";

    return 0;
}