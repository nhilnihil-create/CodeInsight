#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll X,Y,Z,K,i,j,k;scanf("%lld%lld%lld%lld",&X,&Y,&Z,&K);
  ll A[X],B[Y],C[Z];
  for(i=0;i<X;i++) scanf("%lld",&A[i]);
  for(j=0;j<Y;j++) scanf("%lld",&B[j]);
  for(k=0;k<Z;k++) scanf("%lld",&C[k]);
  sort(A,A+X,greater<ll>());
  sort(B,B+Y,greater<ll>());
  sort(C,C+Z,greater<ll>());
  vector<ll> ans;
  for(i=0;i<X && i+1 <= K;i++){
    for(j=0;j<Y && (i+1)*(j+1) <= K;j++){
      for(k=0;k<Z && (i+1)*(j+1)*(k+1) <= K;k++){
        ans.emplace_back(A[i]+B[j]+C[k]);
      }
    }
  }
  sort(ans.begin(),ans.end(),greater<ll>());
  for(i=0;i<K;i++) printf("%lld\n",ans[i]);
}