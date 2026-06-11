#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n,k;cin>>n>>k;
    ll a[1010];
    a[0]=0;
    rep(i,0,n)cin>>a[i+1];
    vector<ll> b;
    rep(i,1,n+1)a[i]+=a[i-1];
    rep(i,0,n){
        rep(j,i+1,n+1){
            b.push_back(a[j]-a[i]);
        }
    }
    ll x=0;
    for(ll i=40;i>=0;i--){
        ll cn=0,pw=1LL<<i;
        x+=pw;
        rep(j,0,b.size()){
            if((b[j]&x)==x)cn++;
        }
        if(cn<k)x-=pw;
    }
    cout<<x<<endl;
}

    







