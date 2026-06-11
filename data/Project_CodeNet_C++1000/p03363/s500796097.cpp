#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N;
  cin >> N;

  vector<int64_t> a(N);
  rep(i, N) { cin >> a[i]; }

  rep(i, N - 1) { a[i + 1] += a[i]; }

  vector<int64_t> b(a);
  b.push_back(0);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());

  int64_t result = 0;
  vector<int> cnt(b.size(), 0);
  cnt[lower_bound(b.begin(), b.end(), 0) - b.begin()] = 1;
  rep(i, N) {
    result += cnt[lower_bound(b.begin(), b.end(), a[i]) - b.begin()]++;
  }
  cout << result << endl;

  return 0;
}