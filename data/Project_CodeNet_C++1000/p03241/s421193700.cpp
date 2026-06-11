#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,m;cin >>n>>m;
    map<ll,ll>mp;
    for (ll i = 1; i*i<=m; ++i) {
        if(m%i==0){
            mp[i]++;
            mp[m/i]++;
        }
    }
    ll ans=1;
    for(auto u:mp){
        if(m/u.first>=n){
            ans=max(ans,u.first);
        }
    }
    cout <<ans <<endl;
    return 0;
}

