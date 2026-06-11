#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n,m,x;
    cin>>n>>m>>x;
    vector<ll>a(m);
    ll ans=0;
    rep(0,i,m){
        cin>>a[i];
        if(x<a[i]){
            ans=i;
            break;
        }
    }
    cout<<min(ans,m-ans);
}