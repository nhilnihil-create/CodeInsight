#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll j = 0; j < n; ++j) cin >> b[j];
    if (accumulate(a.begin(), a.end(), (ll)0) < accumulate(b.begin(), b.end(), (ll)0)) {
        cout << -1 << endl;
        return 0;
    }
    ll luck = 0;
    ll ans = 0;
    vector<ll> diff;
    for (ll k = 0; k < n; ++k) {
        if (a[k] < b[k]) {
            luck += b[k] - a[k];
            ans++;
        }
        else diff.emplace_back(a[k] - b[k]);
    }
    sort(diff.rbegin(), diff.rend());
    ll sum = 0;
    for (ll l : diff) {
        if (sum >= luck) break;
        ans++;
        sum += l;
    }
    cout << ans << endl;
}
