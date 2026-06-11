#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n,k;
    cin>>n>>k;
    ll ans=1;
    rep(0,i,n)ans=min(ans+k,2*ans);
    cout<<ans;
}
