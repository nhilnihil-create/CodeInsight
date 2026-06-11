#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define lb lower_bound
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

int main(){
  ll n,a[200010],b[200010],c[200010],d[200010],k1,k2,t,u,cnt,ans=0;
  cin>>n;
  fr(i,n) cin>>a[i];
  fr(i,n) cin>>b[i];
  fr(i,30){
    t=1ll<<i;
    u=2*t-1;
    fr(i,n) c[i]=a[i]&u;
    fr(i,n) d[i]=b[i]&u;
    sort(d,d+n);
    cnt=0;
    fr(i,n){
      k1=lb(d,d+n,2*t-c[i])-lb(d,d+n,t-c[i]);
      k2=lb(d,d+n,4*t-c[i])-lb(d,d+n,3*t-c[i]);
      cnt+=k1+k2;
    }
    ans+=(cnt%2)*t;
  }
  cout<<ans<<endl;
}