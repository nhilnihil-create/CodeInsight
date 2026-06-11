#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;

int main()
{
    int n, k; cin >> n >> k;
    ll ans = 0;
    for (int b = k+1; b <= n; b++) {
        int m1 = (n - k) / b;
        int m2 = (n - b + 1) / b;
        if (m1 == m2) ans += (m1 + 1) * (b - k) - (k == 0);
        else ans += (m2 + 1) * (b - k) + (n - (k + m1 * b) + 1) - (k == 0);
    }
    cout << ans << endl;
    return 0;
}