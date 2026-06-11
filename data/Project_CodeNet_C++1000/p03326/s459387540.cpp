#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)
const ll MIN_INF = -1e18;

int main() {
    int N, M; cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    rep(i, N) cin >> x[i] >> y[i] >> z[i];
    ll ans = 0;
    rep(i, 1<<3) {
        vector<int> xyzSign(3);
        rep(j, 3) {
            xyzSign[j] = ((i & (1<<j)) ? 1 : -1);
        }
        vector<ll> vec(N);
        rep(j, N) {
            ll tmp = xyzSign[0]*x[j] + xyzSign[1]*y[j] + xyzSign[2]*z[j];
            vec[j] = tmp;
        }
        ll sum = 0;
        sort(ALL(vec));
        reverse(ALL(vec));
        rep(j, M) sum += vec[j];
        chmax(ans, sum);
    }
    cout << ans << endl;
}
