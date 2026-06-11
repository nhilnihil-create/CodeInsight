#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAX = 600000;
ll MOD = 998244353;

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

ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll COM2(ll N, ll R, ll B) {
   ll ans = 1;
   ll tmp1 = COM(N, R) % MOD;
   ll tmp2 = COM(N, B) % MOD;
   ans *= tmp1;
   ans %= MOD;
   ans *= tmp2;
   ans %= MOD;
   return ans;
}

int main() {
   ll A, B, K, N;

   cin >> N >> A >> B >> K;
   
   COMinit();
   ll ans = 0;
   for (ll a = 0; a <= N; a++) {
      if ((K - A * a) % B == 0 && (K - A * a) / B >= 0 && (K - A * a) / B <= N) {
         ll b = (K - A * a) / B;
         // cout << A << "*" << a << "+" << B << "*" << b << "=" << K << endl;
         // cout << COM(N, a) << endl;
         // cout << COM(N, b) << endl;
         // cout << COM2(N, a, b) << endl;
         ans += COM2(N, a, b);
         ans %= MOD;
      }
   }

   cout << ans << endl;
   return 0;
}
