#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(k, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) v[i%k]++;
    for (int a = 1; a <= n; a++) {
        int b = (k - a) % k;
        if (b < 0) b += k;
        if (b * 2 % k != 0) continue;
        ans += v[b] * v[b];
    }
    cout << ans << endl;
    return 0;
}