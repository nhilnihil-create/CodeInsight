#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll H,W,D,i,j,a,Q,l,r;scanf("%lld%lld%lld",&H,&W,&D);
  pair<ll,ll> P[H*W];vector<ll> v[D];
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      scanf("%lld",&a);a--;
      P[a] = make_pair(i,j);
    }
  }
  for(i=0;i<D;i++){
    v[i].emplace_back(0);
    for(j=i+D;j<H*W;j+=D) v[i].emplace_back(v[i].back()+abs(P[j].first-P[j-D].first)+abs(P[j].second-P[j-D].second));
  }
  scanf("%lld",&Q);
  for(i=0;i<Q;i++){
    scanf("%lld%lld",&l,&r);l--;r--;
    printf("%lld\n",v[r%D][r/D]-v[l%D][l/D]);
  }
}