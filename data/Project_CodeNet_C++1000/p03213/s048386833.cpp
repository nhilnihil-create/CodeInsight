#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<double,ll,ll>T;
#define PI 3.14159265358979
const int MAX = 510000;
const int MOD = 1000000007;
//この設定だとn<10^7が限界。maxの０を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
  int N;
  cin>>N;
  COMinit();
  map< ll, int > ret;
 for(ll j=2;j<=N;j++){
   ll n=j;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n]++;
 }
  ll a=0,b=0,c=0,d=0,e=0;
  ll z=0;
  for(auto k:ret){
  	if(k.second>=2){a++;}
    if(k.second>=4){b++;}
    if(k.second>=14){c++;}
    if(k.second>=24){d++;}
    if(k.second>=74){e++;}
  }
  ll ans=0ll;
  ans+=e;
  ans+=d*(a-1);
  ans+=c*(b-1);
  ans+=b*(b-1)*(a-2)/2;
  cout<<ans;
} 