#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int64_t N;
  cin >> N;
  // 4/N = 1/h + 1/n + 1/w
  // 4 = N/h + N/n + N/w
  // 4 = (nwN + hwN + hnN) / hnw
  // 4*hnw = nwN + hwN + hnN
  // 4hnw - nwN - hnN = hwN
  // n(4hw - wN - hN) = hwN

  for (int64_t h = 1; h <= 3500; ++h) {
    for (int64_t w = 1; w <= 3500; ++w) {
      int64_t hwN = h * w * N;
      int64_t nTmp = 4 * h * w - w * N - h * N;
      if (nTmp <= 0) continue;
      if (hwN % nTmp == 0) {
        cout << h << " " << w << " " << hwN / nTmp << endl;
        return 0;
      }
    }
  }
  return 0;
}