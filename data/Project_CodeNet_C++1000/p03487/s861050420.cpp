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

    map<ll,ll> mp;

    for (ll i = 0; i < n; i++){
        mp[a[i]]++;
    }

    ll ans = 0;
    for (auto p : mp){
        if (p.first <= p.second){
            ans += (p.second - p.first);
        }
        else{
            ans += p.second;
        }
    }

    cout << ans << endl;
    
}