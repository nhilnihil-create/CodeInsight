#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 1; i * i < n; i++) {
        ll c = n / i - 1;
        if (n % i == 0 && n % c != 0) ans += c;
    }

    cout << ans << endl;
    return 0;
}
