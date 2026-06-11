#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vector<T>>;
using vl = vector<ll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const ld EPS = 1e-11;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r)-1; i >= (l); i--)

void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N, K;
    cin >> N >> K;
    vl A(N);
    rep(i, N) cin >> A[i];
    vl suml;
    rep(i, N) {
        ll tmp = 0;
        repe(j, i, N) {
            tmp += A[j];
            suml.eb(tmp);
        }
    }

    ll ans = 0;
    repr(i, 41) {
        ll cnt = 0, tmp = ans + (1ll << i);
        rep(i, N * (N + 1) / 2) if ((suml[i] & tmp) == tmp) cnt++;
        // cout << tmp << " " << cnt << endl;
        if (cnt >= K) ans = tmp;
    }
    cout << ans << endl;
    return 0;
}