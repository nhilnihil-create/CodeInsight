#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
using ll=long long;
using namespace std;
ll x[110000],y[110000];
ll a[110000],d[110000],amax[110000],dmax[110000];
main(){
  ll n,c;
  cin>>n>>c;
  rep(i,0,n)cin>>x[i]>>y[i];

  a[0]=y[0];
  d[n-1]=y[n-1];

  rep(i,1,n) a[i]=a[i-1]+y[i];
  irep(i,n-2,0)d[i]=d[i+1]+y[i];

  // 0 to n
  ll ans1=0;
  amax[0]=max((ll)0,y[0]-x[0]);
  rep(i,1,n)amax[i]=max(a[i]-x[i],amax[i-1]);
  ans1=amax[n-1];

  // n to 0
  ll ans2=0;
  dmax[n-1]=max((ll)0,y[n-1]-(c-x[n-1]));
  irep(i,n-2,0)dmax[i]=max(d[i]-(c-x[i]),dmax[i+1]);
  ans2=dmax[0];

  //  clockwise to anticlockwise
  ll ans3=0;
  rep(i,0,n){
    ll tmp=a[i]-x[i]*2+dmax[i+1];
    ans3=max(ans3,tmp);
  }

  // anticlockwise to clockwise
  ll ans4=0;
  irep(i,n-1,0){
    ll tmp2=d[i]-(c-x[i])*2+amax[i-1];
    ans4=max(ans4,tmp2);
  }
  ll ans5=max(max(ans1,ans2),max(ans3,ans4));
  cout<<ans5<<endl;
}