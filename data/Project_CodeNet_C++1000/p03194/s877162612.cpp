#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
pair<ll,ll> g(ll a, ll x, ll p){
    if(p==1){
        ll r;
        if(a==x) r=0;
        else if(a>x) r=2;
        else r=1;
        return {a,r};
    }
    pair<ll,ll> ans=g(a,x,p/2);
    ll r=ans.second;
    if(r==2) return {-1,2};
    ll k=sqrt(x);
    ll z=ans.first;
    if(z > k){
        return {-1,2};
    }
    z*=z;
    if(p%2!=0){
        ll t=x/a;
        if(z > t) return {-1,2};
        z*=a;
    }
    if(z==x) r=0;
        else if(z>x) r=2;
        else r=1;
        return {z,r};
} 
ll f(ll st, ll end, ll x ){
    if(st > end) return -1;
    ll mid=(st+end)/2;
    ll ans=g(mid,x,n).second;
    if(ans==0) return mid;
    if(ans==1) return f(mid+1,end,x);
    return f(st,mid-1,x);
}
int main() {
        ll p;
    cin>>n>>p;
    vector<ll> v;
    for(ll i=1;i<=sqrt(p);i++){
        if(p%i==0){
            v.push_back(i);
            if(p/i != i) v.push_back(p/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto x: v){
        ll ans=f(1,x,x);
        if(ans!=-1){
            cout<<ans; return 0;
        }
    }
}