#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    // greatest divisor of M smaller than or equal to M/N
    ll ans = 0;
    for (ll i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            if (i * N <= M) ans = max(ans, i);
            if ((M / i) * N <= M) ans = max(ans, M / i);
        }
    }
    cout << ans << endl;
}