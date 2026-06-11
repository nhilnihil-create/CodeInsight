#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(ll i=0;i<(n);i++)

const ll INF=1000000000000000000;
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>x(n);
    rep(i,n)cin>>x[i];
    ll ans=INF;
    for(ll i=0;i<n-k+1;i++){
        ll dx=abs(x[i]);
        ll dy=abs(x[i+k-1]);
        dx+=abs(x[i]-x[i+k-1]);
        dy+=abs(x[i+k-1]-x[i]);
        ll d=min(dx,dy);
        ans=min(ans,d);
    }
    cout<<ans<<endl;

}