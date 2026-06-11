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

int A, B;
string S;

int main() {
  cin >> A >> B;
  cin >> S;
  repe(i, 1, A + B + 1) {
    if (i == A + 1) {
      if (S[i - 1] != '-') {
        cout << "No" << endl;
        return 0;
      }
      continue;
    }

    char c = S[i - 1] - '0';
    if (c < 0 || c > 9) {
      cout << "No" << endl;
      return 0;
    }
    continue;
  }
  cout << "Yes" << endl;
}
