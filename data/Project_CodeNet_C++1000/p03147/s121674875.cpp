#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    int n;
    cin >> n;
    int h[n];
    rep (i, 0, n) cin >> h[i];
    bool chk = 1;
    int ans = 0;
    while (chk) {
        int cnt = 0;
        int now = 0;
        int sum = inf;
        rep (i, 0, n) {
            if (h[i] == 0) {
                if (sum != inf) {
                    rep (j, now, i) h[j] -= sum;
                    ans += sum;
                }
                now = i + 1;
                sum = inf;
            } else {
                sum = min (sum, h[i]);
            }
        }
        if (sum != inf) {
            rep (j, now, n) h[j] -= sum;
            ans += sum;
        }
        chk = 0;
        rep (i, 0, n) {
            if (h[i] > 0) chk = 1;
            // cout << h[i] << " ";
        }
        cout << "\n";
    }
    cout << ans << "\n";
}