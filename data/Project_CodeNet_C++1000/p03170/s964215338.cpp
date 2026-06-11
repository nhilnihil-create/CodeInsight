#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<bool> dp(k + 1);
  dp[0] = false;
  for (int i = 1; i <= k; ++i) {
    bool flag = false;
    for (int j = 0; j < n; ++j) {
      if (i - a[j] >= 0 && dp[i-a[j]] == false) {
        flag = true;
        break;
      }
    }
    dp[i] = flag;
  }
  if (dp[k]) {
    cout << "First\n";
  } else {
    cout << "Second\n";
  }
  return 0;
}
