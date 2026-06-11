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
    unordered_map<ll,int>mp;
    ll n;cin >>n;
    for (int i = 0; i < n; ++i) {
        ll a;cin >>a;
        mp[a]++;
    }
    ll ans=0;
    for(auto p:mp){
        ans+=((p.second-p.first)<0)?p.second:p.second-p.first;
    }
    cout <<ans <<endl;
    return 0;
}
