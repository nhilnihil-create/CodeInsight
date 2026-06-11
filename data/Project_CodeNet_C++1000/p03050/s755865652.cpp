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

int main() {
    ll N; cin >> N;
    ll ans = 0;
    for (ll i = 1; i+1 < N/i; i++) {
        if (N % i == 0) {
            ans += N/i - 1;
        }
    }
    cout << ans << endl;
}