#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
#define PRYES(x) PR((x) ? "Yes" : "No")
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;

    vector<bool> values(N + 1, false);
    values[1] = true;
    for (ll i = 2; i <= N; ++i) {
        ll v = i * i;
        while (v <= N) {
            values[v] = true;
            v *= i;
        }
    }

    for (ll i = N; i >= 0; --i) {
        if (values[i]) {
            PR(i);
            break;
        }
    }

    return 0;
}