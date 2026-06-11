#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  int N, a, b, c, dp[3]{};
  cin >> N;
  while (cin >> a >> b >> c) {
    int ma = max(dp[1], dp[2]), mb = max(dp[0], dp[2]), mc = max(dp[0], dp[1]);
    dp[0] = a + ma;
    dp[1] = b + mb;
    dp[2] = c + mc;
  }
  cout << *max_element(dp, dp + 3) << endl;
}
