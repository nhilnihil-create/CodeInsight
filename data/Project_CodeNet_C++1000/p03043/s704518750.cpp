#include <bits/stdc++.h>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, k;
  std::cin >> n >> k;

  double ans = 0.0;
  rep(i, n) {
    int score = i + 1;
    double num = 1.0;
    while (score <= k - 1) {
      score *= 2;
      num /= 2;
    }
    ans += num;
  }
  ans /= n;
  std::cout << fixed << setprecision(10) << ans << std::endl;

  return 0;
}
