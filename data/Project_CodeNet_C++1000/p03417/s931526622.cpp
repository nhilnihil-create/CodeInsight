#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    ll n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        if (n == 1 && m == 1) {
            cout << 1 << endl;
            return 0;
        }
        cout << max(0LL, max(n, m) - 2) << endl;
        return 0;
    } else if (n == 2 || m == 2) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = (n - 2) * (m - 2);
    cout << ans << endl;
}