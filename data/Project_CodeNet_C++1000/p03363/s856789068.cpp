#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
  ll n;cin>>n;
  vll sum(n+1,0);
  map<ll,ll> m;
  ll ans=0;
  m[0]++;
  rep(i,0,n){
    ll a;cin>>a;
    sum[i+1]=sum[i]+a;
    m[sum[i+1]]++;
  }
  for(auto u:m){
      ll tmp=u.second;
      ans+=((tmp-1)*tmp)/2;
  }
  cout<<ans<<endl;
}

