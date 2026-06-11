#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 998244353
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()
#define ADD(a, b) a = (a + b) % MOD

ll pow(ll x, ll n)
{
  if (n == 0)
    return 1;
  ll res = pow(x * x % MOD, n / 2);
  if (n & 1)
    res = res * x % MOD;
  return res;
}

ll inv(ll n)
{
  return pow(n, MOD - 2);
}

vector<ll> fact(300030);
void calc_fact()
{
  fact[0] = 1;
  REP(i, 300030)
  fact[i + 1] = (i + 1) * fact[i] % MOD;
}

ll comb(ll n, ll r)
{
  if (n < r)
    return 0;
  if (n < 0 || r < 0)
    return 0;
  return fact[n] * inv(fact[n - r] * fact[r] % MOD) % MOD;
}

int main()
{
  ll N, A, B, K;
  cin >> N >> A >> B >> K;
  calc_fact();
  ll ans = 0;
  for (ll r = 0; r <= N; ++r)
  {
    ll tmp = K - A * r;
    if (tmp < 0 || tmp % B != 0)
      continue;
    ll b = tmp / B;
    if (N < b)
      continue;
    ADD(ans, comb(N, r) * comb(N, b) % MOD);
  }
  cout << ans << endl;
  return 0;
}
