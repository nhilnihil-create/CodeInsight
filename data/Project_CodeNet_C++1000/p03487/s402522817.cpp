#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    ll n; cin >> n;

    map<ll, ll> mp;
    ll ans = 0;    
    for (ll i = 0; i < n; i++) {
        ans++;
        ll tmp_a; cin >> tmp_a;
        mp[tmp_a]++;

        if (tmp_a == mp[tmp_a]) {
            ans -= tmp_a;
        }        
    }

    cout << ans << endl;
    return 0;
}