#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MOD = 998244353;
const int MAXN = 300100;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return (ll)a * b % MOD;
}

int pot(int a, int b) {
  if (!b) return 1;
  if (b % 2) return mul(a, pot(a, b - 1));
  int k = pot(a, b / 2);
  return mul(k, k);
}

int inv(int a) {
  return pot(a, MOD - 2);
}

int fak[MAXN];

int choose(int n, int k) {
  return mul(fak[n], inv(mul(fak[k], fak[n - k])));
}

int n, a, b;
ll k;

int main() {
  fak[0] = 1;
  FOR(i, 1, MAXN) fak[i] = mul(fak[i - 1], i);
  cin >> n >> a >> b >> k;
  ll sol = 0;
  REP(i, n + 1) {
    ll tream = (k - (ll)i * a) / b;
    if (tream * b != k - (ll)i * a) continue;
    if (tream > n || tream < 0) continue;
    sol = add(sol, mul(choose(n, i), choose(n, tream)));
  }

  cout << sol << endl;
  return 0;
}
