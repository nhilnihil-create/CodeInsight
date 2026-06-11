#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,c;
    cin >> n >> c;
    vector<vector<pair<ll,ll>>> subrokuga(c);
    for(i = 0;i < n;++i){
        ll s,t,ch;
        cin >> s >> t >> ch;
        --ch;
        subrokuga.at(ch).emplace_back(s,t);
    }
    for(i = 0;i < c;++i){
        sort(all(subrokuga.at(i)));
    }
    vector<vector<pair<ll,ll>>> rokuga(c);
    for(i = 0;i < c;++i){
        if(subrokuga.at(i).size() == 0) continue;
        pair<ll,ll> tmp;
        rep(j, subrokuga.at(i).size()){
            if(j == 0){
                tmp = subrokuga.at(i).at(j);
            }else{
               if(subrokuga.at(i).at(j).first == tmp.second){
                    tmp.second = subrokuga.at(i).at(j).second;
                }else{
                    rokuga.at(i).emplace_back(tmp);
                    tmp = subrokuga.at(i).at(j);
                }
            }  
        }
        rokuga.at(i).emplace_back(tmp);
    }
    vector<ll> sche(2e5,0);
    for(i = 0;i < c;++i){
        rep(j, rokuga.at(i).size()){
            ll s = rokuga.at(i).at(j).first;
            ll t = rokuga.at(i).at(j).second;
            ++sche.at(s-1);
            --sche.at(t);
        }
    }
    for(i = 1;i < sche.size();++i){
        sche.at(i) += sche.at(i-1);
    }
    ll ans = 0;
    for(i = 0;i < sche.size();++i){
        ans = max(ans, sche.at(i));
    }
    cout << ans << endl;
    return 0;
}