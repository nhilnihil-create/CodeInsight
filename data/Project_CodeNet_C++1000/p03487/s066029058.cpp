#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    map<ll,ll>mp;
    rep(i,n){
        mp[a[i]]++;
    }
    ll cnt=0;
    for(auto p:mp){
        if(p.first==p.second)cnt+=0;
        else if(p.second>p.first)cnt+=p.second-p.first;
        else cnt+=p.second;
    }
    cout<<cnt<<endl;
}


