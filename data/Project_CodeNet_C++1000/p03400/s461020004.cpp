#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n,d,x;
    cin>>n>>d>>x;
    ll ans=x;
    rep(0,i,n){
        ll a;
        cin>>a;
        ans+=(d+a-1)/a;
        //cout<<ans<<endl;
    }
    cout<<ans;
}