#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<ll> X(N), Y(N), Z(N);
    REP(i, 0, N) cin >> X[i] >> Y[i] >> Z[i];

    ll ans = 0;
    for (int bit = 0; bit < (1 << 3); bit++) {
        vector<ll> V(N);
        REP(i, 0, N) {
            V[i] += ((bit & 1) ? -X[i] : X[i]);
            V[i] += ((bit & 2) ? -Y[i] : Y[i]);
            V[i] += ((bit & 4) ? -Z[i] : Z[i]);
        }
        sort(ALL(V), greater<>());

        ll total = 0;
        REP(i, 0, M) total += V[i];
        ans = max(ans, total);
    }
    cout << ans << endl;
    return 0;
}