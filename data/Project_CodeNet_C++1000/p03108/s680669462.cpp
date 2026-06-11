#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
ll N,M;
ll rank_[100005];
ll par[100005];
ll size_[100005];
void uf_init(ll n_){
for(ll i=0;i<n_;i++){
rank_[i]=0;
  par[i]=i;
  size_[i]=1;
}
}
ll find(ll x){
if(par[x]==x)
  return x;
  else{
  return par[x]=find(par[x]);
  }
}
void unite(ll x,ll y){
x=find(x);y=find(y);
  if(x==y)
    return;
  else if(rank_[x]<rank_[y]){
    par[x]=y;size_[y]+=size_[x];
  }else{
  par[y]=x;size_[x]+=size_[y];
    if(rank_[x]==rank_[y])rank_[x]++;
  }
}
bool same(ll x,ll y){
x=find(x);y=find(y);
  return x==y;
}
ll SIZE(ll x){
x=find(x);
  return size_[x];
}
int main(){
  cin>>N>>M;uf_init(N);
  vector<P>A(M);
  for(int i=0;i<M;i++){
  ll a,b;cin>>a>>b;a--;b--;
    P p(a,b);
    A[i]=p;
  }vector<ll>ans(M);
  ans[M-1]=(N*(N-1))/2;
  for(ll i=M-2;0<=i;i--){
  ll ans1=ans[i+1];
    ll a=A[i+1].first;
    ll b=A[i+1].second;
    if(!same(a,b)){
    ll x=SIZE(a);ll y=SIZE(b);
      ans1-=(x*y);unite(a,b);
    }ans[i]=ans1;
  }for(int i=0;i<M;i++)
    cout<<ans[i]<<endl;
  return 0;
}