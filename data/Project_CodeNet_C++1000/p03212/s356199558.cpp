#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
map<ll,ll> mp;
ll h(ll x){
    ll tot=1;
    for(int i=0;i<x;i++)tot*=10;
    return tot;
}
void f(ll x,ll y,ll z){
    if(z==7&&x<=n){ans++;}
    if(x>n)return ;
    f(x+h(y)*3,y+1,z|1);
    f(x+h(y)*5,y+1,z|2);
    f(x+h(y)*7,y+1,z|4);
}
int main(void){
    cin>>n;
    f(0,0,0);
    cout<<ans<<endl;
}
