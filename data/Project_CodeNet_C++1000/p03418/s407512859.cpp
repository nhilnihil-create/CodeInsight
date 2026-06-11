#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
map<string, int> mp;

int main() {
    ll ans = 0;
    ll n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << n * n << endl;
        return 0;
    }

    for (int j = 1, i = m + 1; i <= n; i++, j++) {
        ans += n / i * j;
        ll tmp = 0;
        tmp = max(0ll, n % i - m + 1);
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}