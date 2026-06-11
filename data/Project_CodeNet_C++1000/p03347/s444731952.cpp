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
    int a[n];
    rep (i, 0, n) {
        cin >> a[i];
        if (i == 0) {
            if (a[i] != 0) {
                cout << "-1\n";
                return 0;
            }
        } else {
            if (a[i] - a[i - 1] > 1) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    int ans = 0;
    per (i, 1, n) {
        if (a[i] == a[i - 1] + 1) {
            ans++;
        } else {
            ans += a[i];
        }
    }
    cout << ans << "\n";
}
