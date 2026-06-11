#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

const ll INF = 1e18;

ll N, X, x[200000], csum[200001];

ll mult(ll a, ll b) {
    if ((a * b) / b != a) return INF;
    return a * b;
}

int main() {
    cin >> N >> X;
    REP(i, N) cin >> x[i];
    REP(i, N) csum[i + 1] = csum[i] + x[i];
    reverse(csum, csum + N + 1);

    ll ans = INF;
    FOR(k, 1, N + 1) {
        ll tmp = (N + k) * X;
        for (ll i = 0; i * k < N; i++) {
            tmp += mult((2 * (max(i, 1LL) + 1) + 1), (csum[i * k] - csum[min(N, (i + 1) * k)]));
            tmp = min(tmp, INF);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}