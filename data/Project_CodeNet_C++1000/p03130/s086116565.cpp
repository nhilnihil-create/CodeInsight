#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    map<int,int>mp;
    rep(i,3){
        int a,b; cin>>a>>b;
        mp[a]++; mp[b]++;
    }
    int mx=0;
    for(auto&p:mp){
        mx=max(mx,p.second);
    }
    if(mp.size()==4&&mx<=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}