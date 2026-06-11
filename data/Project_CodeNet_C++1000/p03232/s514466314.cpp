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

const int MAXN = 100100;
const int MOD = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
  return a;
}

int mul(int a, int b) {
  return (ll) a * b % MOD;
}

int pot(int a, int b) {
  if (!b) return 1;
  if (b % 2) return mul(a, pot(a, b - 1));
  int k = pot(a, b / 2);
  return mul(k, k);
}


int inv(int x) {
  return pot(x, MOD - 2);
}

int n, a[MAXN], p[MAXN], N, P[MAXN];

int main() {
  scanf("%d",&n);
  FOR(i, 1, n + 1) scanf("%d",&a[i]);
  FOR(i, 1, n + 1) p[i] = add(p[i - 1], a[i]);
  FOR(i, 1, n + 1) P[i] = add(P[i - 1], p[i]);

  N = 1;
  FOR(i, 1, n + 1) N = mul(N, i);

  int sol = mul(N, p[n]);
  FOR(l, 1, n - 1) {
    int x = mul(N, inv(mul(l + 1, l + 2)));
    x = mul(x, 2);
    int suff = add(P[n - 1], -P[l]);
    int pref = P[n - l - 1];
    int s = add(suff, -pref);
    sol = add(sol, mul(x, s));
  }

  FOR(i, 1, n) {
    int x = mul(N, inv(i - 1 + 2));
    sol = add(sol, mul(x, p[i]));
  }

  FOR(j, 2, n + 1) {
    int x = mul(N, inv(n - j + 2));
    sol = add(sol, mul(x, add(p[n], -p[j-1])));
  }

  cout << sol << endl;
  return 0;
}
