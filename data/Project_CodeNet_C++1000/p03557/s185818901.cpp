#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n),c(n),dpb(n+1,0),dpc(n+1,0);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];
    rep(i,n) cin>>c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans=0,cnta=0,cntb=0;
    for(ll i=1;i<=n;i++){
        while(cnta<n&&a[cnta]<b[i-1]) cnta++;
        dpb[i]=dpb[i-1]+cnta;
    }
    for(ll i=1;i<=n;i++){
        while(cntb<n&&b[cntb]<c[i-1]) cntb++;
        dpc[i]=dpc[i-1]+dpb[cntb];
    }
    cout<<dpc[n]<<endl;
    return 0;
}