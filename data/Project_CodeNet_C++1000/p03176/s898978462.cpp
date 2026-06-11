#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
ll dat[800020];
void init(int n_){
n=1;
  while(n<n_)
    n*=2;
  }
void update(ll k,ll a){
k+=n-1;
  dat[k]=a;
  while(0<k){
  k=(k-1)/2;
    dat[k]=max(dat[2*k+1],dat[2*k+2]);
  }
}
ll query(ll a,ll b,ll k,ll l,ll r){
if(a<=l && r<=b)
  return dat[k];
  else if(b<=l || r<=a)
    return 0;
  else
    {
  ll val=query(a,b,2*k+1,l,(l+r)/2);
    ll var=query(a,b,2*k+2,(l+r)/2,r);
    return max(val,var);
  }
}
ll N;
int main(){
  cin>>N;
  vector<ll>h(N);
  vector<ll>a(N);
  for(int i=0;i<N;i++)
    cin>>h[i];
  for(int i=0;i<N;i++)
    cin>>a[i];
  init(200005);
  for(int i=0;i<N;i++){
  ll M=query(0,h[i],0,0,n);
    update(h[i],a[i]+M);
  }cout<<dat[0]<<endl;
  return 0;
}