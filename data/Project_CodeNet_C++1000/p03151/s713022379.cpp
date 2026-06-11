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
  vll a(n),b(n),big(0);
  ll suma=0,sumb=0;
  rep(i,0,n){
    cin>>a[i];
    suma+=a[i];
  }
  rep(i,0,n){
    cin>>b[i];
    sumb+=b[i];
  }
  if(suma<sumb){
    cout<<-1<<endl;return 0;
  }
  ll ans=0,cnt=0;
  rep(i,0,n){
      if(a[i]>b[i]){
        big.push_back(a[i]-b[i]);
        suma-=a[i];
        sumb-=b[i];
        ans++;
      }
    if(a[i]==b[i])cnt++;
  }
  ans=n-cnt-ans;
  sort(big.begin(),big.end());
  reverse(big.begin(),big.end());
  ll i=0;
  while(suma<sumb){
    suma+=big[i];
    i++;
  }
  cout<<ans+i<<endl;
}
