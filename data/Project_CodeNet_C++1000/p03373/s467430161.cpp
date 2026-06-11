#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = 0;
    if (a + b <= c * 2) {
        ans += a * x + b * y;
    } else {
        int minv = min(x, y);
        ans += c * minv * 2;
        x -= minv, y -= minv;

        if (x > 0) {
            if (a <= c * 2)
                ans += a * x;
            else
                ans += c * 2 * x;
        } else if (y > 0) {
            if (b <= c * 2)
                ans += b * y;
            else
                ans += c * 2 * y;
        }
    }

    cout << ans << endl;
    return 0;
}
