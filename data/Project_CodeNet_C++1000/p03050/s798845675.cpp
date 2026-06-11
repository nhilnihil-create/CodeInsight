#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll x = 1; x * x < n; x++) {
        if (n % x != 0) continue;
        ll m = (n / x) - 1;
        if (x < m) ans += m;
    }

    cout << ans << endl;
    return 0;
}