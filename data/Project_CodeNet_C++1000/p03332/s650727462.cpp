#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;
#define MOD 998244353LL
#define MAXN 300300

ll fakt[MAXN];

ll pow(ll a, ll b)
{
  if (b == 0) return 1LL;

  if (b == 1) return a;

  if (b % 2 == 1) return a * pow(a, b - 1) % MOD;

  ll ret = pow(a, b / 2LL);

  return ret * ret % MOD;
}

int main()
{
  fakt[0] = 1;
  for (int i = 1; i < MAXN; i++)
    fakt[i] = fakt[i - 1] * ll(i) % MOD;
  ll n, a, b, k;
  scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
  ll reza = 0LL;
  for (ll x = 0LL; x <= n; x++) {
    ll by = k - a * x;
    if (by % b == 0 && by / b >= 0 && by / b <= n) {
      ll y = by / b;
      reza += fakt[n] * pow(fakt[n - x], MOD - 2) % MOD * pow(fakt[x], MOD - 2) % MOD * fakt[n] % MOD * pow(fakt[n - y], MOD - 2) % MOD * pow(fakt[y], MOD - 2) % MOD;
      reza %= MOD;
    }
  }
  cout << reza;
  return 0;
}
