#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    map<ll, ll> mp;
    for (ll i : sum) mp[i]++;
    ll ans = 0;
    for (auto i : mp) if (i.second >= 2) ans += i.second * (i.second - 1) / 2;
    cout << ans << endl;
}
