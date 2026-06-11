#include <iomanip>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t n, m, d;
  cin >> n >> m >> d;
  double answer;
  if (d == 0) {
    answer = (double)(m - 1) * (1.0 / (double)(double)n);
  } else {
    answer = (double)(m - 1) * ((double)(2 * (n - d)) / (double)(n * n));
  }
  cout << setprecision(20) << answer << endl;
  return 0;
}
