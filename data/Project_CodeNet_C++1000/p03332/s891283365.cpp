#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
const long long MOD =  998244353;
const int MAX = 300001;
long long fac[MAX];
long long finv[MAX];
long long inv[MAX];

void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  long long N;
  long long A;
  long long B;
  long long K;
  cin >> N >> A >> B >> K;
  comb_init();
  long long ans = 0;
  for(long long i = 0; i <= N; i++){
    if((K - i * A) % B == 0 && (K - i * A) / B <= N){
      ans = (ans + (comb(N, i) * comb(N, (K - i * A) / B)) % MOD) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
