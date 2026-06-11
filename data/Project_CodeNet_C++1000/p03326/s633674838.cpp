#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
struct cake{ll a,b,c;};
const ll inf = 1001001001001001001;
int main(){
  ll N,M,i,j,k,l,ans = -inf;scanf("%lld%lld",&N,&M);
  cake C[N];
  for(i=0;i<N;i++) scanf("%lld%lld%lld",&C[i].a,&C[i].b,&C[i].c);
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      for(k=0;k<2;k++){
        ll V[N] = {};
        for(l=0;l<N;l++){
          V[l] += (i ? C[l].a:-C[l].a);
          V[l] += (j ? C[l].b:-C[l].b);
          V[l] += (k ? C[l].c:-C[l].c);
        }
        sort(V,V+N,greater<ll>());
        ans = max(ans,accumulate(V,V+M,0LL));
      }
    }
  }
  printf("%lld\n",ans);
}