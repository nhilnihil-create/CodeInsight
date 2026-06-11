#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ll long long

using namespace std;

const ll MOD = 998244353;
const int MAXN = 300100;
ll fak[MAXN];

ll mul(ll a, ll b) {
  return (a * b) % MOD;
}

ll add(ll a, ll b) {
  return (a + b) % MOD;
}

ll pow(ll x, ll a) {
  ll out = 1, pot = x;
  while (a) {
    if (a & 1) out = mul(out, pot);
    pot = mul(pot, pot);
    a >>= 1;
  }
  return out;
}

ll choose(ll n, ll k) {
  return mul(fak[n], mul(pow(fak[k], MOD - 2), pow(fak[n - k], MOD - 2)));
}

int main() {
  ios_base::sync_with_stdio(false);

  fak[0] = 1;
  FOR(i, 1, MAXN) fak[i] = mul(fak[i - 1], i);

  ll n, a, b, k;
  cin >> n >> a >> b >> k;

  ll out = 0;
  REP(i, n + 1) {
    ll tr = k - a * i;
    ll j = tr / b;
    if (tr % b != 0) continue;
    if (i > n || j > n || j < 0) continue;
    out = add(out, mul(choose(n, i), choose(n, j)));
  }

  cout << out << "\n";

  return 0;
}