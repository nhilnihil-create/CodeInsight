#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=unsigned long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<62;
const double eps=1e-5;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    ll n,X;cin>>n>>X;
    vector<ll> x(n+10),sum(n+10);
    for(int i=1;i<=n;i++){
        cin>>x[i];
        sum[i]=sum[i-1]+x[i];
    }
    ll ans=LINF;
    for(ll k=1;k<=n;k++){
        ll s=0,c=1;
        s+=(sum[n%k]-sum[0])*(n/k+c+1ULL)*(n/k+c+1ULL);
        for(ll i=n%k+k;i<=n;i+=k){
            --c;
            ll id=0;
            if(i>2*k)id=i-2*k;
            s+=(sum[i]-sum[i-k]-sum[i-k]+sum[id])*(n/k+c+1LL)*(n/k+c+1LL);
        }
        s+=(n+k)*X;
        s+=sum[n]-sum[n-k];
        ans=min(ans,s);
    }
    cout<<ans<<endl;
}
