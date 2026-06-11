#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll a,b,k;
    cin>>a>>b>>k;

    ll n=b-a+1;
    //vector<ll> num(n);
    //iota(num.begin(),num.end(),a);
    if(n<=k){
        for(int i=a;i<=b;i++) cout<<i<<"\n";
        return 0;
    }

    set<ll> ans;
    for(ll i=a;i<a+k;i++) ans.insert(i);
    for(ll i=b-k+1;i<=b;i++) ans.insert(i);

    for(auto itr=ans.begin();itr!=ans.end();itr++) cout<<*itr<<"\n";
    return 0;
}