#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n,k;cin>>n>>k;
    ll a[100010];
    rep(i,0,n)cin>>a[i];
    ll an=0;
    for(ll i=43;i>=0;i--){
        ll cn1=0;
        rep(j,0,n){
            if(a[j]&(1LL<<i))cn1++;
        }
        if(cn1*2<n&&(an+(1LL<<i)<=k))an+=(1LL<<i);
    }
    ll ans=0;
    rep(i,0,n)ans+=(a[i]^an);
    cout<<ans<<endl;
}

    







