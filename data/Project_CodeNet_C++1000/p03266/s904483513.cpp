#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k & 1) {
        ll t = n / k;
        t = pow(t, 3);
        ans = t;
    } else {
        ll t = n / k;
        ll t2 = n / (k / 2);
        t2 = (t2 + 1) / 2;
        ans = pow(t, 3) + pow(t2, 3);
    }
    cout << ans << endl;
}