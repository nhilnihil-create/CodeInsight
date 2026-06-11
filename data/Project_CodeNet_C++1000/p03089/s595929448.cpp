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
  vector<int> b(N);
  rep(i, N) {
    cin >> b[i];
    b[i]--;
  }

  vector<int> result;
  rep(i, N) {
    int idx = -1;
    rrep(j, b.size()) {
      if (b[j] == j) {
        idx = j;
        break;
      }
    }
    if (idx < 0) {
      cout << -1 << endl;
      return 0;
    }
    b.erase(b.begin() + idx);
    result.push_back(idx);
  }

  rrep(i, N) { cout << result[i] + 1 << "\n"; }

  return 0;
}