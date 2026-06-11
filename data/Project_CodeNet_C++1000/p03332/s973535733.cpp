#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll Pow(ll A, ll N){
  if (N == 0) return 1;
  if (N % 2 == 0) return Pow(A*A%MOD2, N/2);
  return A * Pow(A*A%MOD2, N/2) % MOD2;
}

ll N, A, B, K, nCr[int(3e5+5)];

int main(){
  cin >> N >> A >> B >> K;
  nCr[0] = 1;
  for (ll i = 1; i <= N; i++){
    nCr[i] = nCr[i-1] * (N+1-i) % MOD2;
    nCr[i] *= Pow(i, MOD2-2); nCr[i] %= MOD2;
  }

  ll ans = 0;
  for (ll i = 0; i <= N; i++){
    ll rest = K - A * i;
    if (rest % B != 0) continue;
    rest /= B;
    if (rest > N || rest < 0) continue;

    ll now = nCr[i] * nCr[rest] % MOD2;
    ans += now; ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
