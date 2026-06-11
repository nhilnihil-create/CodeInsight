#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    ll ans = abs(x - a[0]);
    for (int i=1; i<n; i++) ans = gcd(ans, abs(x - a[i]));
    
    cout << ans << endl;
    
    return 0;
}