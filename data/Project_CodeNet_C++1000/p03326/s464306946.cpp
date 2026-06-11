// 15:03-

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define EACH(i, a) for (auto &&i : a)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RFOR(i, a, b) for (int i = (int)b - 1; i >= (int)a; --i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FOR(i, 1, int(n) + 1)
#define RREP(i, n) RFOR(i, 0, n)
#define RREPS(i, n) RFOR(i, 1, int(n) + 1)
#define ALL(x) (x).begin(), (x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define debug(x) cout << #x << ": " << x << endl

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define INF (1L << 30)
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cout << *i << " ";
  cout << endl;
}
template <class T>
void pvp(T a, T b) {
  for (T i = a; i != b; ++i)
    cout << "(" << i->first << ", " << i->second << ") ";
  cout << endl;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
int in() {
  int x;
  scanf("%d", &x);
  return x;
}

using ll = long long;
#define int ll

//***** basic func *****//
int power_mod(int a, int b) {
  // return (a**b)%MOD (O(log b))
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    b >>= 1;
  }
  return res;
}

// int fact[510000], fact_inv[510000];  // n!, (n!)^-1 mod MOD
// // calc fact (in main routine)
// fact[0] = 1;
// REP(i, n) { fact[i + 1] = fact[i] * (i + 1) % MOD; }
// fact_inv[n] = power_mod(fact[n], MOD - 2);
// RREP(i, n) { fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD; }
// int comb_mod(int n, int r) {
//   return ((fact[n] * fact_inv[r]) % MOD * fact_inv[n - r] % MOD);
// }

//**********

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  int x[1000], y[1000], z[1000];
  cin >> N >> M;
  REP(i, N) { cin >> x[i] >> y[i] >> z[i]; }

  int ans = 0;
  int total[8][1000];
  REP(i, N) {
    REP(j, 8) {
      if (j & 4) {
        total[j][i] = x[i];
      } else {
        total[j][i] = -x[i];
      }
      if (j & 2) {
        total[j][i] += y[i];
      } else {
        total[j][i] += -y[i];
      }
      if (j & 1) {
        total[j][i] += z[i];
      } else {
        total[j][i] += -z[i];
      }
    }
  }
  REP(i, 8) { sort(total[i], total[i] + N); }
  REP(i, 8) {
    // debug(i);
    int sum = 0;
    REP(j, M) {
      sum += total[i][N - 1 - j];
      // debug(total[i][N - 1 - j]);
    }
    chmax(ans, sum);
    // debug(sum);
  }

  cout << ans << endl;

  return 0;
};
