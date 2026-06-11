#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> D(13, 0);
  D[0]++;
  rep(i, N) {
    int d;
    cin >> d;
    D[d]++;
  }
  rep(i, 13) {
    if ((D[i] >= 3) || (D[i] >= 2 && (i == 0 || i == 12))) {
      cout << 0 << endl;
      return 0;
    }
  }

  int answer = 0;
  rep(i, (1 << 11)) {
    vector<int> TIME(25, 0);
    TIME[0] = 1;
    TIME[24] = 1;
    if (D[12] == 1) TIME[12] = 1;
    bool ok = true;
    rep(j, 11) {
      if (D[j + 1] == 0) continue;
      if (i & (1 << j)) {
        if (D[j + 1] == 1) {
          TIME[j + 1] = 1;
        } else {
          TIME[j + 1] = 1;
          TIME[24 - j - 1] = 1;
        }
      } else {
        if (D[j + 1] == 1) {
          TIME[24 - j - 1] = 1;
        } else {
          ok = false;  // duplicate pattern
        }
      }
    }

    if (ok) {
      int minTime = 24;
      int prev = 0;
      for (int j = 1; j <= 24; ++j) {
        if (TIME[j] == 0) continue;
        minTime = min(minTime, j - prev);
        prev = j;
      }
      answer = max(answer, minTime);
    }
  }
  cout << answer << endl;
  return 0;
}
