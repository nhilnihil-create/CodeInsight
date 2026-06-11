#include<bits/stdc++.h>
//#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
//using namespace atcoder;
typedef long long ll;
int main(){
  ll N,K,i,j,sum;scanf("%lld%lld",&N,&K);
  ll a[N];
  vector<ll> B;
  for(i=0;i<N;i++) scanf("%lld",&a[i]);
  for(i=0;i<N;i++){
    sum = a[i];
    B.emplace_back(sum);
    for(j=i+1;j<N;j++){
      sum += a[j];
      B.emplace_back(sum);
    }
  }
  ll ans = 0;
  vector<ll> C;
  for(i=40;i>=0;i--){
    for(j=0;j<B.size();j++){
      if(B[j] & (1LL<<i)) C.emplace_back(B[j]);
    }
    if(C.size() >= K){
      ans += 1LL<<i;
      B.swap(C);
    }
    vector<ll>().swap(C);
  }
  printf("%lld\n",ans);
}