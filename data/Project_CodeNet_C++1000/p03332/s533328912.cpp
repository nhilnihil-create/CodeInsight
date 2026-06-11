#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

ll gcd(ll x, ll y){
  if(x%y==0) return y;
  return gcd(y, x%y);
}

const int MAX = 1000000;
const int MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  ll N, A, B; ll K; cin >> N >> A >> B >> K;
  if(A<B) swap(A, B); int cnta = -1, cntb = -1;
  rep(i, N+1){
    if((K - A*i)%B==0 && K>=A*i){
      cnta = i; cntb = (K - A*i)/B; break;
    }
  }
  if(cnta==-1){
    cout << 0 << endl; return 0;
  }
  COMinit();
  ll G = gcd(A, B);
  if(K%G){
    cout << 0 << endl; return 0;
  }
  ll ans = 0;
  while(cnta<=N){
    ans+=(COM(N, cnta)*COM(N, cntb)%mod);
    ans%=mod;
    cnta+=(B/G); cntb-=(A/G);
  }
  cout << ans << endl;
}