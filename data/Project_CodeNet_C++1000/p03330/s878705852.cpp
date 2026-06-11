#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll N, C;
ll D[40][40];
ll c[1000][1000];
map<ll, ll> m[3];

int main() {
  cin >> N >> C;
  repe(i, 1, C) {
    repe(j, 1, C) { cin >> D[i][j]; }
  }
  repe(i, 1, N) {
    repe(j, 1, N) {
      cin >> c[i][j];
      m[(i + j) % 3][c[i][j]]++;
    }
  }

  ll ans = INF;
  repe(i, 1, C) {
    repe(j, 1, C) {
      if (j == i) continue;
      repe(k, 1, C) {
        if (k == i || k == j) continue;

        ll d = 0;
        for (auto e : m[0]) {
          ll color = e.first;
          ll num = e.second;
          d += D[color][i] * num;
        }
        for (auto e : m[1]) {
          d += D[e.first][j] * e.second;
        }
        for (auto e : m[2]) {
          d += D[e.first][k] * e.second;
        }
        chmin(ans, d);
      }
    }
  }

  cout << ans << endl;
}
