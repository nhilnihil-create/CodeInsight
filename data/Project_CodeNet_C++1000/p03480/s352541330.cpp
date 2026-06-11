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

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;
const long long MINF = LLONG_MIN;

// -------------------------------------------------------

string S;

int main() {
  cin >> S;
  int ans = 0;

  int len = S.size();
  if (len % 2 == 1) {
    int mid = len / 2;
    char midc = S[mid];
    int ii = len / 2;
    repe(i, 0, len / 2) {
      if (S[mid - i] != midc || S[mid + i] != midc) {
        ii = i - 1;
        break;
      }
    }
    ans = mid + ii + 1;
  } else {
    int mid = len / 2;
    char midc = S[mid];
    if (midc != S[mid - 1]) {
      ans = 1;
    } else {
      int ii = len / 2 - 1;
      repe(i, 0, len / 2 - 1) {
        if (S[mid - 1 - i] != midc || S[mid + i] != midc) {
          ii = i - 1;
          break;
        }
      }
      ans = mid + ii + 1;
    }
  }

  int ans2 = 0;
  if (len % 2 == 1) {
    ans2 = len / 2 + 1;
  } else {
    ans2 = len / 2;
  }

  cout << max(ans, ans2);
}
