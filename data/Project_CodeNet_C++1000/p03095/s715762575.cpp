#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

const ll mod=1e9+7;
int main(){
    int n; string s;
    cin>>n>>s;
    map<char,int>mp;
    rep(i,n){
        mp[s[i]]++;
    }
    for(auto&p:mp)p.second++;
    ll ans=1;
    for(auto&p:mp){
        ans*=p.second;
        ans%=mod;
    }
    cout<<ans-1<<endl;
}