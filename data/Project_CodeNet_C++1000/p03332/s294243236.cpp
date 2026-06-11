#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll frac[300005];

ll comb(ll a, ll b) {
  ll ue = frac[a];
  ll shita1=1, shita2=1;
  ll tmpshita1, tmpshita2, two, h;
  h = mod - 2;
  while(h>0) {
    two = 1;
    tmpshita1 = frac[b];
    tmpshita2 = frac[a-b];
    while(2*two<h) {
      two *= 2;
      tmpshita1 *= tmpshita1;
      tmpshita2 *= tmpshita2;
      tmpshita1 %= mod;
      tmpshita2 %= mod;
    }
    h -= two;
    shita1 *= tmpshita1;
    shita2 *= tmpshita2;
    shita1 %= mod;
    shita2 %= mod;
  }
  return ue*shita1%mod*shita2%mod;
}

int main() {
  frac[0] = 1;
  for(ll i=1;i<300005;++i) {
    frac[i] = frac[i-1]*i%mod;
  }
  ll N, A, B, K;
  cin>>N>>A>>B>>K;
  ll ans = 0;
  for(ll x=0;x<=N;++x) {
    if(K<A*x) continue;
    if((K-A*x)%B==0) {
      if((K-A*x)/B>N) continue;
      ans += comb(N, x)*comb(N, (K-A*x)/B)%mod;
      ans %= mod;
    }
  }
  cout<<ans<<endl;
}

