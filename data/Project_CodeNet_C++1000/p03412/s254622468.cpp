#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
const double EPS=1E-8;
////////////////////////////////////////



int main() {
   // ios::sync_with_stdio(false);cin.tie(0);
    
    ll n;scanf("%lld",&n);
    ll a[n],b[n];rep(i,0,n-1)scanf("%lld",&a[i]);
    rep(i,0,n-1)scanf("%lld",&b[i]);
    ll ans=0;
    rep(k,1,29){
        ll p=(ll)1<<k;
        ll c[n],d[n];
        rep(i,0,n-1){
            d[i]=b[i]%p;
            c[i]=a[i]%p;
        }
        sort(d,d+n);
        ll sum=0;
        rep(i,0,n-1){
            sum+=lower_bound(d,d+n,p-c[i])-lower_bound(d,d+n,p/2-c[i]);
            sum+=lower_bound(d,d+n,2*p-c[i])-lower_bound(d,d+n,3*p/2-c[i]);
        }
        if(sum%2)ans+=1<<(k-1);
    }
    //cout<<ans<<endl;
    printf("%lld",ans);
    return 0;
}
//ios::sync_with_stdio(false);cin.tie(0);
