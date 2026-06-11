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
int X[201010];
int Xsorted[201010];

int main() {
  cin >> N;
  rep(i, 0, N) {
    cin >> X[i];
    Xsorted[i] = X[i];
  }
  sort(Xsorted, Xsorted + N);
  int mid = N / 2;
  int midr = Xsorted[mid];
  int midl = Xsorted[mid - 1];

  rep(i, 0, N) {
    if (X[i] >= midr) {
      cout << midl << endl;
    } else {
      cout << midr << endl;
    }
  }
}