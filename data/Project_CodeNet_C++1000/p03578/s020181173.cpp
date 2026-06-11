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
    sort(d.begin(), d.end());
    sort(t.begin(), t.end());
    bool ans = true;
    if (n < m){
        ans = false;
    }
    else{
        ll c = 0;
        for (ll i = 0; i < n; i++){
            if (d[i] == t[c]){
                c++;
            }
        }
        if (c < m){
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