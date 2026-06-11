#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    ll a[n];
    ll ans = 0;
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll sum[n + 1];
    sum[0] = 0;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    for (ll i = 0; i < n+1; i++) {
        mp[sum[i]]++;
    }
    for (auto i : mp) {
        ans += (i.second * (i.second - 1)) / 2;
    }
    cout << ans << endl;
}
