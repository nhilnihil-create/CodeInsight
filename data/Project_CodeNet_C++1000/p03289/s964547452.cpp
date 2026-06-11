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
string S;

int main() {
  cin >> S;
  if (S[0] != 'A') {
    cout << "WA";
    return 0;
  }
  int n = 0;
  for (int i = 2; i <= S.size() - 2; i++) {
    if (S[i] == 'C') {
      n++;
    }
  }
  if (n != 1) {
    cout << "WA";
    return 0;
  }
  int nn = 0;
  for (int i = 0; i < S.size(); i++) {
    if ('a' <= S[i] && S[i] <= 'z') {
      nn++;
    }
  }
  if (nn != S.size() - 2) {
    cout << "WA";
    return 0;
  }
  cout << "AC";
}
