#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int q;
  cin>>q;
  REP(i,q) {
    ll a,b;
    cin>>a>>b;
    if (a<b) swap(a, b);
    ll s = sqrt(a*b);
    while (s*s < a*b) ++s;
    while (s*s >= a*b) --s;
    ll ans = 2*s;
    if (s*(s+1) >= a*b) --ans;
    if (b <= s) --ans;
    cout<<ans<<endl;
  }
  return 0;
}
