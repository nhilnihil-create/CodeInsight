#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

const int mod=1e9+7;

int main(){
    int n;
    string s;
    cin>>n>>s;
    ll ans=1;
    map<char,int>mp;
    rep(i,n)mp[s[i]]++;
    for(auto&p:mp){
        ans=ans*(p.second+1)%mod;
    }
    cout<<ans-1<<endl;
    return 0;
}