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
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll frac[300005], shita[300005];

void prepare() {
  ll h = mod1 - 2;
  ll two;
  for(int i=0;i<300005;++i) shita[i] = 1;
  ll tmp[300005];
  while(h>0) {
    two = 1;
    for(int i=0;i<300005;++i) tmp[i] = frac[i];
    while(2*two<h) {
      two *= 2;
      for(int i=0;i<300005;++i) {
        tmp[i] *= tmp[i];
        tmp[i] %= mod1;
      }
    }
    h -= two;
    for(int i=0;i<300005;++i) {
      shita[i] *= tmp[i];
      shita[i] %= mod1;
    }
  }
}

ll comb(ll a, ll b) {
  return frac[a]*shita[a-b]%mod1*shita[b]%mod1;
}

int main() {
  frac[0] = 1;
  for(ll i=1;i<300005;++i) {
    frac[i] = frac[i-1]*i%mod1;
  }
  prepare();
  ll N, A, B, K;
  cin>>N>>A>>B>>K;
  ll ans = 0;
  for(ll x=0;x<=N;++x) {
    if(K-A*x<0) continue;
    if((K-A*x)%B!=0) continue;
    if((K-A*x)/B>N) continue;
    ans += comb(N, x)*comb(N, (K-A*x)/B)%mod1;
    ans %= mod1;
  }
  cout<<ans<<endl;
}

