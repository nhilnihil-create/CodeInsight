#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;++i)cin >> a[i];
    for (ll i = 1;i < n;++i)a[i] += a[i - 1];
    a.push_back(0);
    sort(a.begin(), a.end());
    ll ans = 0;
    ll cnt = 1;
    ll prev = 1e10;
    for (ll i = 0;i <= n;++i) {
        if (a[i] == prev) ++cnt;
        else {
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
            prev = a[i];
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;
}