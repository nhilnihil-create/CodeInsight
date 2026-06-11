//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    ll n,k,ba; cin>>n>>k;
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    sort(al(a));
    ll l=1;
    for(ll i=1;i<=64;i++){
        l*=2;
        if(a[n-1]<=l-1 && k<=l-1){
            ba=l-1;
            l=i; break;
        } 
    }
    vector<ll> v1(l,0),v0(l,0),sum(l,0),sum2(l,0);
    ll r=1;
    rep(i,l){
        rep(j,n){
            if(a[j]&(1LL<<i)) v0[i]+=r;
            else v1[i]+=r;
        }
        r*=2;
    }
    sum[0]=max(v0[0],v1[0]);
    ll ans=v0[0];
    sum2[0]=(k&(1LL<<(l-1)) ? v1[l-1] : v0[l-1]);
    rep(i,l-1){
        sum2[i+1]=sum2[i]+(k&(1LL<<(l-2-i)) ? v1[l-2-i] : v0[l-2-i]);
        sum[i+1]=sum[i]+max(v0[i+1],v1[i+1]);
        ans+=v0[i+1];
    }
    ans=max(ans,sum2[l-1]);
    rep(i,l){
        ll cnt=0;
        if(k&(1LL<<(l-1-i))){
            cnt=v0[l-1-i];

            if(i!=0) cnt+=sum2[i-1];
            if(l-1-i!=0) cnt+=sum[l-2-i];
        }
        ans=max(ans,cnt);
    }

    cout<<ans<<endl;
}