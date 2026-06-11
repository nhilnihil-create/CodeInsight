#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 100100100100100;
int main(){
  ll a,b,q,x,i,ls,lt,rs,rt;scanf("%lld%lld%lld",&a,&b,&q);
  ll s[a+2],t[b+2];s[0] = t[0] = -inf;s[a+1] = t[b+1] = inf;
  for(i=1;i<=a;i++) scanf("%lld",&s[i]);
  for(i=1;i<=b;i++) scanf("%lld",&t[i]);
  sort(s,s+a+2);sort(t,t+b+2);
  for(i=0;i<q;i++){
    scanf("%lld",&x);
    auto sa = lower_bound(s,s+a+2,x),ta = lower_bound(t,t+b+2,x);
    rs = *sa;rt = *ta;
    ls = *(sa-1);lt = *(ta-1);
    printf("%lld\n",min({x-min(ls,lt),max(rs,rt)-x,min(x-ls,rt-x)*2+max(x-ls,rt-x),min(x-lt,rs-x)*2+max(x-lt,rs-x)}));
  }
}