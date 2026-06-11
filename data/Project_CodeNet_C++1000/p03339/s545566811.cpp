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
int N;
string S;
int Easts[301010];

int main() {
  cin >> N >> S;
  rep(i, 0, N) {
    if (S[i] == 'E') {
      Easts[i + 1] = Easts[i] + 1;
    } else {
      Easts[i + 1] = Easts[i];
    }
  }

  int ans = inf;
  repe(i, 1, N) {
    int cost = 0;
    cost += (i - 1) - Easts[i - 1];
    cost += Easts[N] - Easts[i];
    chmin(ans, cost);
  }
  cout << ans << endl;
}