#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll n;
    cin >> n;
    map<ll, ll> mp;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
        auto itr = mp.find(a[i]);
        if(itr == end(mp))mp[a[i]] = 1;
        else mp[a[i]]++;
    }
    sort(ALL(a), greater<ll>());
    ll ans = 0;
    rep(i, a.size()){
        if(mp[a[i]]<1)continue;
        rep(j, 35){
            if((1LL<<j)<a[i])continue;
            ll t = (1LL<<j)-a[i];
            auto itr = mp.find(t);
            if(itr!=end(mp)){
                if(t==a[i]){
                    if(mp[t]>1){
                        ans++, mp[t]--, mp[a[i]]--;
                        break;
                    }
                }
                else if(mp[t]>0){
                    ans++, mp[t]--, mp[a[i]]--;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}