#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int a[100][100];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> a_sum(n);
  for (int i = n-1; i >= 0; i--) {
    if (i == n-1) {
      a_sum[i] = a[1][i];
    } else {
      a_sum[i] = a_sum[i+1] + a[1][i];
    }
  }

  int current = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    current += a[0][i];
    ans = max(ans, current + a_sum[i]);
  }
  cout << ans << endl;
  return 0;
}