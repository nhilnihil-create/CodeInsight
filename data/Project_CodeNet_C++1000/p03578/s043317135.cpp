#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N) { cin >> d[i]; }

  int M;
  cin >> M;
  vector<int> t(M);
  rep(i, M) { cin >> t[i]; }

  if (N < M) {
    cout << "NO" << endl;
    return 0;
  }

  sort(d.begin(), d.end());
  sort(t.begin(), t.end());

  int s = 0;
  int j = 0;
  rep(i, M) {
    while (j < N && d[j] < t[i]) {
      j++;
    }
    if (d[j] == t[i]) {
      s++;
      j++;
    }
  }
  cout << (s == M ? "YES" : "NO") << endl;
  return 0;
}