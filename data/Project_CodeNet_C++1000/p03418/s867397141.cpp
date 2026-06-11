#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,k;
long long ans=0;
int main() {
  scanf("%d%d",&n,&k);
  for (int i=k+1;i<=n;++i) {
    int lim=n/i;
    ans+=1ll*(lim)*(i-k);
    ans+=max(0ll,1ll*(n%i)-max(0ll,1ll*k-1));
  }
  printf("%lld\n",ans);
  return 0;
}
