#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    map<ll, ll> mp;
    cin >> n >> m;
    ll a[n] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        mp[a[i] % m]++;
    }

    ll ans = 0;
    for (auto e : mp) {
        if (e.first == 0) ans += e.second;
        ans += e.second * (e.second - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}
