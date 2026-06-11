#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int64_t> X(N);
  vector<int64_t> Y(N);
  vector<int64_t> Z(N);
  rep(i, N) { cin >> X[i] >> Y[i] >> Z[i]; }

  vector<tuple<int, int, int>> pattern = {
      {+1, +1, +1}, {+1, +1, -1}, {+1, -1, +1}, {+1, -1, -1},
      {-1, +1, +1}, {-1, +1, -1}, {-1, -1, +1}, {-1, -1, -1}};
  int64_t answer = 0;
  for (auto& pat : pattern) {
    vector<int64_t> XYZ(N);
    rep(i, N) {
      XYZ[i] = X[i] * get<0>(pat) + Y[i] * get<1>(pat) + Z[i] * get<2>(pat);
    }
    sort(XYZ.rbegin(), XYZ.rend());
    int64_t tmp_ans = 0;
    rep(i, M) { tmp_ans += XYZ[i]; }
    answer = max(answer, tmp_ans);
  }
  cout << answer << endl;
  return 0;
}
