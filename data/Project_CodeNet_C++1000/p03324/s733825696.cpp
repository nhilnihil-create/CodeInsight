#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    ll D, N;
    cin >> D >> N;

    ll MAX_VAL = 10000 * 100 * 10;
    ll ans;
    if (D == 0) {
        ll count = 0;
        for (ll i = 1; i <= MAX_VAL; i++) {
            if (i % 100 != 0) {
                count++;
                if (count == N) ans = i;
            }
        }
    } else if (D == 1) {
        ll count = 0;
        for (ll i = 1; i <= MAX_VAL; i++) {
            if (i % 100 == 0 && i % 10000 != 0) {
                count++;
                if (count == N) ans = i;
            }
        }
    } else if (D == 2) {
        ll count = 0;
        for (ll i = 1; i <= MAX_VAL; i++) {
            if (i % 10000 == 0 && i % 1000000 != 0) {
                count++;
                if (count == N) ans = i;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
