#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans = 0;
    if (a >= b - 1) {
        ans = k + 1;
    } else {
        k -= a - 1;
        ans = a;
        ans += (b - a) * (k / 2);
        if (k % 2) ans++;
    }
    cout << ans << endl;
    return 0;
}