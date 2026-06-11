#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;
    vector<ll> datas[2];
    REP(i, 2) {
        datas[i].resize(N);
        REP(j, N) {
            cin >> datas[i][j];
        }
    }

    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        ll s = 0;
        for (ll j = 0; j <= i; ++j) {
            s += datas[0][j];
        }
        REP2(j, i, N) {
            s += datas[1][j];
        }
        sum = max(s, sum);
    }

    PR(sum);
    return 0;
}