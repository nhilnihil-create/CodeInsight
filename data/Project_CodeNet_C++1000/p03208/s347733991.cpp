#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    vector<ll> h(n);
    for (ll i = 0;i < n;i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll x = n-k+1;
    ll ans = h[n-1];
    for (ll i = 0; i < x; i++){
        ans = min(ans, h[i+k-1]-h[i]);
    }

    cout << ans << endl;
}