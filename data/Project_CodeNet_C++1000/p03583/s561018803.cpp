#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll N,h,n;scanf("%lld",&N);
  for(h=1;h<=3500;h++){
    for(n=1;n<=3500;n++){
      if(4*h*n-N*n-N*h == 0) continue;
      if((N*h*n)%(4*h*n-N*n-N*h) == 0 && (N*h*n)/(4*h*n-N*n-N*h) > 0){
        printf("%lld %lld %lld\n",h,n,(N*h*n)/(4*h*n-N*n-N*h));
        return 0;
      }
    }
  }
}