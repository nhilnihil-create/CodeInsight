#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<bool>> bulbs(M, vector<bool>(N, false));
  for (int m = 0; m < M; ++m) {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
      int s;
      cin >> s;
      bulbs[m][--s] = true;
    }
  }
  vector<int> checks(M);
  for (int m = 0; m < M; ++m) {
    cin >> checks[m];
  }
  
  int res = 0;
  for (int i = 0; i < pow(2, N); ++i) {
    bitset<10> bs(i);
    vector<bool> switch_on(N, false);
    for (int j = 0; j < N; ++j) {
      switch_on[j] = bs.test(j);
    }
    bool success = true;
    for (int b = 0; b < M; ++b) {
      vector<bool> bulb = bulbs[b];
      int cnt_on = 0;
      for (int n = 0; n < N; ++n) {
        if (bulb[n] && switch_on[n]) {
           ++cnt_on;
        }
      }
      if (cnt_on % 2 != checks[b]) {
        success = false;
        break;
      }
    }
    if (success) {
      ++res;
    }
  }
  cout << res << endl;

  return 0;
}
