#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dat[1200010];
ll n;
void init(ll n_){
  n=1;
while(n<=n_)n*=2;
  for(ll i=0;i<2*n-1;i++)
    dat[i]=0;
}
void add(ll k,ll a){
k+=n-1;
  dat[k]+=a;
  while(0<k){
  k=(k-1)/2;
    dat[k]=dat[2*k+1]+dat[2*k+2];
  }
}
ll query(ll a,ll b,ll k,ll l,ll r){
if(a<=l && r<=b)
  return dat[k];
  else if(b<=l || r<=a)
    return 0;
  else {
  ll val=query(a,b,2*k+1,l,(l+r)/2);
    ll var=query(a,b,2*k+2,(l+r)/2,r);
    return (val+var);
  }
}
ll N;
int main(){
  cin>>N;
  vector<ll>a(N);
  for(ll i=0;i<N;i++)
    cin>>a[i];
  ll left=0;ll right=1000000001;vector<ll>b(N+1);
  while(1<right-left){
    b[0]=0;
  ll mid=left+(right-left)/2;
    for(ll i=0;i<N;i++)
      if(a[i]<=mid)
        b[i+1]=b[i]+1;
    else
      b[i+1]=b[i];
    for(ll i=0;i<=N;i++)
      b[i]=(2*b[i]-i+N);
  init(3*N);
    ll sum=0;
    for(ll i=0;i<=N;i++){
    sum+=query(0,b[i],0,0,n);
      add(b[i],1);
     }
  if(N*(N+1)<4*sum)
    right=mid;
    else
      left=mid;
  
  }cout<<right<<endl;
  return 0;
}