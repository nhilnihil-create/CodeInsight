#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N,i,j,x,ans = 0;scanf("%lld",&N);
  bool a[N+1][20];
  for(i=0;i<N;i++){
    scanf("%lld",&x);
    for(j=0;j<20;j++){
      a[i][j] = x%2;
      x >>= 1;
    }
  }
  ll l = 0,r = 0,sum[20] = {};
  bool ok;
  while(r <= N){
    ok = true;
    for(i=0;i<20;i++) ok &= sum[i] <= 1;
    if(ok){
      ans += r-l;
      for(i=0;i<20;i++) sum[i] += a[r][i];
      r++;
    } else {
      for(i=0;i<20;i++) sum[i] -= a[l][i];
      l++;
    }
  }
  printf("%lld\n",ans);
}