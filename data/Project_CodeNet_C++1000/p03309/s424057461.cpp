#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()


const ll inf=4e18;

int main(){
    ll n; cin>>n;
    vector<ll> p(n);
    rep(i,n) cin>>p[i];
    rep(i,n) p[i]-=(i+1);
    sort(btoe(p));
    ll med,ans=inf, an=0;
    if(n%2==0) med=(p[n/2]+p[n/2-1])/2;
    else med=p[n/2];
    for(ll i=med-10; i<=med+10; ++i){
        an=0;
        rep(j,n) an+=abs(p[j]-i);
        ans=min(ans,an);
    }
    cout<<ans<<endl;
    return 0;
}