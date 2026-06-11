#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    vector<ll>v;
    for(ll i=x;i<=y;){
        v.push_back(i);
        if(i*2<=y)i=i*2;
        else break;
    }
    cout<<v.size();
}