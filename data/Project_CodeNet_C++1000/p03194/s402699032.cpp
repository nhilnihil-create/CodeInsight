#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    ll n, p; cin >> n >> p;

    ll ans = 1;
    if (n == 1) {
        cout << p << endl;
        return 0;
    } else if (p == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (ll i = 2; i*i <= p; i++) {
        ll count = 0;
        while (p % i == 0) {
            count++;
            if (count == n) {
                ans *= i;
                count = 0;
            }
            p/=i;
        }
    }
    cout << ans << endl;

    return 0;
}