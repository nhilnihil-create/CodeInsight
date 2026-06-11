#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    a[0]=0;
    rep(i,n){
        cin>>a[i+1];
        a[i+1]+=a[i];
    }
    vector<ll> v;
    v.reserve(n*(n+1)/2);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;++j){
            v.push_back(a[j+1]-a[i]);
        }
    }
    int sz=v.size();
    ll ans=0;
    for(int i=40;i>=0;--i){
        int cnt=0;
        rep(j,sz){
            if(v[j]&(1LL<<i)){
                ++cnt;
            }
        }
        if(cnt>=k){
            rep(j,sz){
                if(!(v[j]&(1LL<<i))){
                    v[j]=0;
                }
            }
            ans+=(1LL<<i);
        }
    }
    cout<<ans<<endl;
}
