#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int

int main() {
    int n, k;
    cin >> n >> k;
    ll x[n];
    rep(i, n) {
        cin >> x[i];
    }
    ll ans = 100000000000000007;
    for (int i = 0; i < n - k + 1; i++) {
        int r = i + k - 1;
        ll A = min(abs(x[i]), abs(x[r])), B = max(abs(x[i]), abs(x[r]));
        if (x[i] * x[r] < 0) {
            ans = min(ans, 2 * A + B);
        } else {
            ans = min(ans, B);
        }
    }

    if (ans == 100000000000000007) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
