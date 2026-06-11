#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define ll long long
#define debug(x) cout << "debug: " << x << endl
#define MOD 1e9 + 7
#define INF 1e9

template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  int A[210];
  cin >> N;
  rep(i, N) cin >> A[i];
  int res = 0;

  while (true) {
    bool exist_odd = false;
    rep(i, N) {
      if (A[i] % 2 != 0)
        exist_odd = true;
    }
    if (exist_odd)
      break;

    rep(i, N) { A[i] /= 2; }
    ++res;
  }

  cout << res << endl;

  return 0;
}
