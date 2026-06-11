#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

ll n,a[100001];
const int mod=1000000007;
ll inv[100001],si[100002];
int inv_init(ll n,ll p){
    inv[1]=1;
    FOR(i,2,n+1) inv[i]=p-(p/i)*inv[p%i]%p;
    return 0;
}
int main(){
    cin>>n;
    rep(i,n) cin>>a[i];
    inv_init(n,mod);
    ll fac=1;
    FOR(i,1,n+1){
        si[i]=(inv[i]+si[i-1])%mod;
        fac*=i;
        fac%=mod;
    }
    ll ans=0;
    rep(i,n){
        ans+=a[i]*(si[i+1]-1+si[n-i])%mod;
        ans%=mod;
    }
    ans=ans*fac%mod;
    cout<<ans<<endl;
    return 0;
}