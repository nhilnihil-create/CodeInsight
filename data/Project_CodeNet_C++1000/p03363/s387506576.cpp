#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> s(n + 1, 0);
    map<ll, ll> mp;
    mp[0]++;
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[i];
        mp[s[i + 1]]++;
    }

    ll ans = 0;
    for (auto p : mp) {
        if (p.second >= 2) {
            ans += (p.second) * (p.second - 1) / 2;
        }
    }

    cout << ans << endl;
}