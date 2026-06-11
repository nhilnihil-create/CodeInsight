#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k,i,l,r,ans = 0;scanf("%lld%lld",&n,&k);
  for(i=k+1;i<=n;i++){
    if(i!=1) ans += n/i*(i-k);
    l = n/i*i+k;r = n/i*i+i;
    if(n>=l) ans += min(n-l+1,r-l);
  }
  printf("%lld\n",ans);
}