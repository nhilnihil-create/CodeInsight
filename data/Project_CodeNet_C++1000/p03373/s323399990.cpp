#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b >= 2 * c) {
        if (x > y) {
            cout << min(2 * c * y + (x - y) * a, 2 * c * x) << endl;
        } else {
            cout << min(2 * c * x + (y - x) * b, 2 * c * y) << endl;
        }
    } else {
        cout << a * x + b * y << endl;
    }
    return 0;
}