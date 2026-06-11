#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int64_t N, M;
  cin >> N >> M;
  int64_t mx_l = 0;
  int64_t mn_r = 1000000;
  vector<pair<int64_t, int64_t>> gates(M);
  for (int64_t m = 0; m < M; ++m) {
    int64_t l, r;
    cin >> l >> r;
    gates[m] = {l, r};
    mx_l = max(mx_l, l);
    mn_r = min(mn_r, r);
  }
  int64_t res = 0;
  for (int64_t n = 1; n <= N; ++n) {
    if (mx_l <= n && n <= mn_r) {
      ++res;
    }
  }
  cout << res << endl;
  
  return 0;
}
