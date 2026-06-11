#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll ans=0;
    ll n;cin >>n;
    map<ll,int>mp;
    for (ll i = 1; i*i<=n; ++i) {
        if(n%i==0){
            mp[i]++;
            mp[n/i]++;
        }
    }
    for(auto u:mp){
//        cout <<u.first<<endl;
        ll d=n/u.first;
//        cout <<d<<endl;
        if(mp[d]){
//            cout <<d<<endl;
            if(d-1>u.first) {
                ans += d - 1;
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}