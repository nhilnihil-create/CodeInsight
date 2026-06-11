#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> c;
    ll tmp;
    cin >> tmp;
    c.push_back(tmp);
    for(i = 1;i < n;++i){
        ll tmp1;
        cin >> tmp1;
        if(tmp != tmp1){
            tmp = tmp1;
            c.push_back(tmp);
        }
    }
    n = c.size();
    unordered_map<ll,ll> mp;
    vector<ll> prev(n, -1);
    for(i = 0;i < n;++i){
        if(mp.count(c.at(i))){
            prev.at(i) = mp[c.at(i)];
            mp[c.at(i)] = i;
        }else{
            mp[c.at(i)] = i;
        }
    }
    ll MOD = 1e9+7;
    vector<ll> dp(n+1,1);
    for(i = 1;i < n;++i){
       dp.at(i+1) = dp.at(i)%MOD;
       if(prev.at(i) != -1){
           dp.at(i+1) += dp.at(prev.at(i) + 1);
           dp.at(i+1) %= MOD;
       }
    }
    cout << dp.at(n) << endl;

    return 0;
}