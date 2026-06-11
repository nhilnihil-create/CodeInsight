#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<ll>b(n+1);
    rep(i,n)cin>>a[i];
    b[0]=0;
    for(int i=1; i<=n; ++i){
        b[i]=b[i-1]+a[i-1];
    }
    map<ll,ll>mp;
    rep(i,n+1)mp[b[i]]++;
    ll ans=0;
    for(auto&p:mp){
        if(p.second>=2){
            ll cnt=p.second*(p.second-1)/2;
            ans+=cnt;
        }
    }
    cout<<ans<<endl;
}