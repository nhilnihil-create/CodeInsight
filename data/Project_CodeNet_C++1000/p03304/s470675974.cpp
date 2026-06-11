#include <iostream>
#include <iomanip>

using namespace std;
typedef long long ll;

ll d, n, m;

void solve() {
  // To have d difference, pair should be (1,d+1), ... (n-d, n)
  double p = n - d;
  // If we look at only two elements, all the rest could be anything.
  // (m - 1)C1 * m^(n-2) / m^n * p * 2.0
  double ans = p * (m - 1) / (n * n);
  if (d != 0) {
    ans *= 2.0;
  }
  cout << setprecision(20) << ans << endl;
}

int main() {
  cin >> n >> m >> d;
  solve();
}
