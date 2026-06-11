#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k, a, b;
    cin >> k >> a >> b;

    if (b - a <= 2) {
        cout << k + 1 << "\n";
    }
    else {
        ll ans = a;
        k -= a - 1;
        ans += k / 2 * (b - a) + k % 2;
        cout << ans << "\n";
    }

    return 0;
}