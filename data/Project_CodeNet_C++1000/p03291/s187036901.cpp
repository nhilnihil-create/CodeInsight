#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../lib/dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

struct mint
{
  ll v;
  mint() : v(0) {}
  mint(ll v) : v((v % MOD + MOD) % MOD) {}
};
mint& operator+=(mint& a, mint b) { return a = a.v + b.v; }
mint& operator-=(mint& a, mint b) { return a = a.v - b.v; }
mint& operator*=(mint& a, mint b) { return a = a.v * b.v; }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint operator*(mint a, mint b) { return a *= b; }
mint operator-(mint a) { return 0 - a; }
ostream& operator<<(ostream& os, const mint& a) { return (os << a.v); }

// 0: なにもない
// 1: Aの数
// 2: ABの数
// 3: ABCの数
mint dp[4][100005];

void solve()
{
  string s;
  cin >> s;
  int N = s.size();
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      if (s[i] == '?') {
        dp[j][i + 1] += dp[j][i] * 3;
      } else {
        dp[j][i + 1] += dp[j][i];
      }
    }
    if (s[i] == 'A' || s[i] == '?') {
      dp[1][i + 1] += dp[0][i];
    }
    if (s[i] == 'B' || s[i] == '?') {
      dp[2][i + 1] += dp[1][i];
    }
    if (s[i] == 'C' || s[i] == '?') {
      dp[3][i + 1] += dp[2][i];
    }
  }
  cout << dp[3][N] << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}