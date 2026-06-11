#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    map<ll,ll> mp;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        mp[a]++;
    }
    ll ans =0;
    for(auto itr = mp.begin();itr != mp.end();++itr){
        if(itr->first < itr->second){
            ans += (itr->second -itr->first);
        }else if(itr->first > itr->second){
            ans += itr->second;
        }
    }
    cout << ans << endl;
    

    return 0;
}