#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 998244353;

const int MAX = 510000;
int fac[MAX], finv[MAX], inv[MAX];

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
int COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main() {
  
  COMinit();
  
  int N, A, B, K;
  cin >> N >> A >> B >> K;
  
  int ans = 0;
  for( int a = 0; a <= N; a++ ){
    if( a*A > K ) break;
    //割り切れないときは0組
    if( (K-A*a)%B != 0 ) continue;
    int b = (K-A*a)/B;
    //bがN以上になるときも0組
    if( b > N ) continue; 
    ans += (COM(N, a)%MOD*COM(N, b)%MOD)%MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  
}
