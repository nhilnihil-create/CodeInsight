#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    map<ll,ll> a;
    ll ans = 0, s = 0; a[s]++;
    for(int i=0; i<n; i++){
        ll x; cin >> x;
        s = (s+x) % m;
        ans += a[s];
        a[s]++;
    }
    cout << ans << endl;
}