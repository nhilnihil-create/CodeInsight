#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    ll ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for(int i = 0; i < n; i++){
        ll anum = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll cnum = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        ans += anum * cnum;
    }
    cout << ans << endl;
}