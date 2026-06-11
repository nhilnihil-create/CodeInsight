#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
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

int main()
{
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N)
  cin >> A[i];
  vector<ll> fact(N + 1); // 1!, 2!, N!
  vector<ll> h(N + 1);    // 1/1 + 1/2 + ... + 1/N
  fact[0] = 1;
  h[0] = 0;
  REP(i, N)
  {
    fact[i + 1] = (i + 1) * fact[i] % MOD;
    ADD(h[i + 1], (inv(i + 1) + h[i]) % MOD);
  }
  ll ans = 0;
  REP(i, N)
  {
    ll tmp = A[i] * fact[N] % MOD;
    tmp *= ((h[i + 1] + h[N - i] - h[1]) % MOD) % MOD;
    ADD(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}