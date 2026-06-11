#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    ll n; cin >> n;
    map<ll, ll>mp;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for (auto u : mp) {
        if (u.first <= u.second) {
            ans += u.second  - u.first;
        }
        else if (u.second < u.first) {
            ans += u.second;
        }
    }
    cout << ans << endl;
    return 0;
}