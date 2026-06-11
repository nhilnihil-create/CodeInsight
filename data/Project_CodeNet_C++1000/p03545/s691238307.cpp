#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
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
int A, B, C, D;

string printop(int n) {
  if (n == 1) {
    return "+";
  } else {
    return "-";
  }
}

int main() {
  string S;
  cin >> S;
  A = S[0] - '0';
  B = S[1] - '0';
  C = S[2] - '0';
  D = S[3] - '0';

  for (int i = -1; i <= 1; i += 2) {
    for (int j = -1; j <= 1; j += 2) {
      for (int k = -1; k <= 1; k += 2) {
        int sum = A + i * B + j * C + k * D;
        if (sum == 7) {
          cout << A << printop(i) << B << printop(j) << C << printop(k) << D
               << "=7" << endl;
          return 0;
        }
      }
    }
  }
}
