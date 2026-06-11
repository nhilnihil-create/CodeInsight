#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll k, a, b;
    cin >> k >> a >> b;

    ll ans = 0;
    if (a >= b - 1 || a >= k)
        ans = k + 1;
    else {
        k -= a - 1;
        ans = a + k / 2 * (b - a) + k % 2;
    }

    cout << ans << endl;
    return 0;
}
