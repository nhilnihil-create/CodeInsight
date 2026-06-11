#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> e(n);
    for (ll i = 0; i < n; i++){
        cin >> e[i].first >> e[i].second;
    }

    sort(e.begin(), e.end());

    ll c = 0;
    ll ans = 0;

    for (ll i = 0; i < n; i++){
        if (c + e[i].second <= m){
            c += e[i].second;
            ans += e[i].first * e[i].second;
        }
        else{
            ans += e[i].first * (m-c);
            break;
        }
    }

    cout << ans << endl;
    
}