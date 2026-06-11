#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    ll n;
    cin>>n;
    vector<ll>a;
    for(ll i=1; i*i<=n; ++i){
        if(n%i==0){
            a.push_back(i);
            if(n/i!=i)a.push_back(n/i);
        }
    }
    ll ans=0;
    rep(i,a.size()){
        if(a[i]==1)continue;
        if(n/(a[i]-1)==n%(a[i]-1))ans+=(a[i]-1);
    }
    cout<<ans<<endl;
}
