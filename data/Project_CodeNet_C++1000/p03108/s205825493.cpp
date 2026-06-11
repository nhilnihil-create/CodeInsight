#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll MAX_N = 100000;
ll Par[MAX_N],Rank[MAX_N] = {},Amount[MAX_N];
ll N;
void init(){
  ll i;
  for(i=0;i<N;i++){
    Par[i] = i;
    Amount[i] = 1;
  }
}
ll find(ll x){
  if(Par[x] == x) return x;
  else{
    Par[x] = find(Par[x]);
    Amount[x] = Amount[Par[x]];
    return Par[x];
  }
}
ll amount(ll x){
  find(x);
  return Amount[x];
}
bool same(ll x,ll y){
  return find(x) == find(y);
}
bool unite(ll x,ll y){
  x = find(x);y = find(y);
  if(x == y) return false;
  if(Rank[x] < Rank[y]) swap(x,y);
  Par[y] = x;
  Amount[x] += Amount[y];
  if(Rank[x] == Rank[y]) Rank[x]++;
  return true;
}
int main(){
  ll M,i;scanf("%lld%lld",&N,&M);
  init();
  pair<ll,ll> B[M];
  ll ans[M];
  for(i=M-1;i>=0;i--){
    scanf("%lld%lld",&B[i].first,&B[i].second);
    B[i].first--;B[i].second--;
  }
  ll sum = N*(N-1)/2,now = 0,l,r,lr;
  for(i=0;i<M;i++){
    ans[M-i-1] = sum-now;
    l = amount(B[i].first);r = amount(B[i].second);
    if(unite(B[i].first,B[i].second)){
      lr = amount(B[i].first);
      now += (lr*(lr-1)-l*(l-1)-r*(r-1))/2;
    }
  }
  for(i=0;i<M;i++) printf("%lld\n",ans[i]);
}