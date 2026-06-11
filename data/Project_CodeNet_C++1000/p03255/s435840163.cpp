#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
static const ll INF=10000000000000000000000;
ll N,X;
ll sum[200005];
ll x[200005];
ll a[200005];
int main(){
  cin>>N>>X;
  for(ll i=0;i<N;i++)
    cin>>x[i];
  for(ll i=1;i<=N;i++)
    sum[i]=sum[i-1]+x[i-1];
  a[0]=5;a[1]=5;
  for(ll i=2;i<=200004;i++)
    a[i]=a[i-1]+2;
  ll ans=INF;ll zero=0;
  for(ll i=1;i<=N;i++){
  ll t=i*X;
    for(ll j=0;j*i<=N;j++){
      if((j+1)*i<=N)
    t+=a[j]*(sum[N-i*j]-sum[N-(j+1)*i]);
      else
        t+=a[j]*(sum[N-i*j]-sum[0]);
    }if(t<ans)ans=t;
  }ans+=N*X;
  cout<<ans<<endl;
  return 0;
}
