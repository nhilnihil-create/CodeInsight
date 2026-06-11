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

int main(){
    ll n,k; cin>>n>>k;
    vector<ll> a(n,0),sum(n+1,0);
    rep(i,n){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    vector<ll> data(n*(n+1)/2,0),v(n*(n+1)/2,0);
    ll cnt=0;
    for(ll i=0;i<n;i++)for(ll j=i;j<n;j++){
        data[cnt]=sum[j+1]-sum[i];
        cnt++;
    }
    ll K=0;
    while((1LL<<K)<sum[n]) K++;
    ll ans=0,p=0;
    for(ll i=K;i>=0;i--){
        cnt=0;
        rep(j,n*(n+1)/2){
            if(p>v[j]) continue;
            if((1LL<<i)&data[j]){
                cnt++;
                v[j]=p+1;
            }
            else v[j]=p;
        }
        if(cnt>=k){
            ans+=(1LL<<i); p++;
        }
    }
    cout<<ans<<endl;
}
