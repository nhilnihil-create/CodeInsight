#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n;
    vector<ll> d(n);
    for (ll i = 0;i < n;i++){
        cin >> d[i];
    }
    cin >> m;
    vector<ll> t(m);
    for (ll i = 0;i < m;i++){
        cin >> t[i];
    }
    map<ll,ll> mpd;
    for (ll i = 0; i < n; i++){
        mpd[d[i]]++;
    }
    map<ll,ll> mpt;
    for (ll i = 0; i < m; i++){
        mpt[t[i]]++;
    }
    bool ans = true;
    for (ll i = 0; i < m; i++){
        ll x = t[i];
        if (mpd[x] < mpt[x]){
            ans = false;
        }
    }

    if (ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}