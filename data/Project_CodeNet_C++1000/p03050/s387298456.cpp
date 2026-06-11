#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ll div = n / i;
            if (div - i >= 2) {
                ans += div - 1;
            }
        }
    }
    cout << ans << endl;
}