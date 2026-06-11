#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,x;
    cin >> n >> x;
    vector<ll> s(n);
    for (ll i = 0;i < n;i++){
        cin >> s[i];
    }
    vector<ll> d(n);
    for (ll i = 0;i < n;i++){
        d[i] = abs(s[i]-x);
    }
    ll ans = d[0];
    for (ll i = 1; i < n; i++){
        ans = gcd(ans,d[i]);
    }
    cout << ans << endl;
}