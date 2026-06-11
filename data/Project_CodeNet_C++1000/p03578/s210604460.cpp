#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n; cin >> n;
    vector<ll> d(200000);
    for(ll i=0; i<n; i++) cin >> d[i];
    map<ll, ll> mp;
    ll m; cin >> m;
    vector<ll> t(200000);
    for(ll i=0; i<m; i++){
        cin >> t[i];
        if(mp.count(t[i])){
            mp[t[i]]++;
        }else{
            mp[t[i]] = 1;
        }
    }
    for(ll i=0; i<n; i++){
        if(mp.count(d[i])){
            mp[d[i]]--;
            if(mp[d[i]]==0){
                mp.erase(d[i]);
            }
        }
    }
    if(mp.size()==0) cout << "YES" << endl;
    else             cout << "NO"  << endl;
    return 0;
}