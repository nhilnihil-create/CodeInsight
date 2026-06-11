#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    ll n;
    cin>>n;
    ll a[5];
    ll mn=1e18;
    rep(i,5){
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    ll ans=5;
    if(n%mn!=0)ans+=n/mn;
    else ans+=n/mn-1;
    cout<<ans<<endl;
    return 0;
}