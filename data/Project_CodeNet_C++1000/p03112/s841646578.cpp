#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<int64_t> S(A);
  rep(i, A) cin >> S[i];
  vector<int64_t> T(B);
  rep(i, B) cin >> T[i];

  rep(i, Q) {
    int64_t x;
    cin >> x;
    auto sitr = lower_bound(S.begin(), S.end(), x);
    auto titr = lower_bound(T.begin(), T.end(), x);

    // sitr -> titr or titr -> sitr
    int64_t dist0 = 1e10 * 4;
    if(sitr != S.end() && titr != T.end()) {
      dist0 = max(*sitr, *titr) - x;
    }

    // sitr -> tir-1
    int64_t dist1 = 1e10 * 4;
    if (sitr != S.end() && titr != T.begin()) {
      --titr;
      int64_t dist1a = (*sitr - x) + (*sitr - *titr);
      int64_t dist1b = (x - *titr) + (*sitr - *titr);
      dist1 = min(dist1a, dist1b);
      ++titr;
    }

    // sitr-1 -> titr
    int64_t dist2 = 1e10 * 4;
    if (sitr != S.begin() && titr != T.end()) {
      --sitr;
      int64_t dist2a = (*titr - x) + (*titr - *sitr);
      int64_t dist2b = (x - *sitr) + (*titr - *sitr);
      dist2 = min(dist2a, dist2b);
      ++sitr;
    }

    // sitr -1 -> titr-1
    int64_t dist3 = 1e10 * 4;
    if (sitr != S.begin() && titr != T.begin()) {
      --sitr;
      --titr;
      dist3 = x - min(*sitr, *titr);
    }

    int64_t answer = min(min(dist0, dist1), min(dist2, dist3));
    cout << answer << endl;
  }
  return 0;
}
