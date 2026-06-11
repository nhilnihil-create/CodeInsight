#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll N,i,mc = 0;scanf("%lld",&N);
  ll A[N];
  for(i=0;i<N;i++){
    scanf("%lld",&A[i]);
    if(A[i] < 0) mc++;
    A[i] = abs(A[i]);
  }
  if(mc%2 == 0) printf("%lld\n",accumulate(A,A+N,0LL));
  else printf("%lld\n",accumulate(A,A+N,0LL)-*min_element(A,A+N)*2);
}