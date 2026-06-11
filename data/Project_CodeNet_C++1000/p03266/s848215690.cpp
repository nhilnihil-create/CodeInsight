#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll f(ll n, ll k, ll x) { return (n - x) / k + 1;}

int main() {
    ll n, k;
    cin >> n >> k;
    if (n * 3 < k) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ans += (n / k) * (n / k) * (n / k);
    if (k % 2 == 0) {
        ll x = k / 2;
        ans += f(n, k, x) * f(n, k, x) * f(n, k, x);
    }
    cout << ans << endl;
}
