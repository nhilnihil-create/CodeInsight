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
int A, B, K;

int main() {
  cin >> A >> B >> K;
  set<int> ans;

  for (int i = A; i < A + K && i <= B; ++i) {
    ans.insert(i);
  }
  for (int i = B; i > B - K && i >= A; --i) {
    ans.insert(i);
  }

  auto iter = ans.begin();
  while (iter != ans.end()) {
    cout << *iter << endl;
    ++iter;
  }
}
