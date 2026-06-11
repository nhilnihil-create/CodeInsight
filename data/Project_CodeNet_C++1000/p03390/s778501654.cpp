#include<bits/stdc++.h>
using namespace std;

using ll = long long;


ll foo(ll a, ll b) {
  if(a == b) return (a-1)<<1;
  ll s = a*b-1;
  ll sq = sqrt(s);
  ll ret = (sq-1)*2;
  if (a <= sq-1) ret--;
  for(ll l = sq; l<=sq+1;l++){
    if(l == a) continue;
    ll r = s/l;
    if(r == b) r--;
    if(r < sq) break;
    ret++;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d",&n);
  while(n--) {
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b) swap(a,b);
    printf("%lld\n",foo(a,b));
  }
}
