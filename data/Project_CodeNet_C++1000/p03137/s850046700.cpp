#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<ll> x(m);
    for (ll i = 0;i < m;i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    
    vector<ll> d(m-1);
    for (ll i = 0;i < m-1;i++){
        d[i] = x[i+1] - x[i];
    }
    sort(d.begin(), d.end());
    ll ans = 0;

    for (ll i = 0; i < max(0LL, m-n); i++){
        ans += d[i];
    }

    cout << ans << endl;

}