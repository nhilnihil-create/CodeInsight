#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }
    ll ans = a[0];

    for (ll i = 1; i < n; i++){
        ans = gcd(ans, a[i]);
    }

    cout << ans << endl;
}