#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, d;
  cin >> n >> m >> d;
  cout << setprecision(16);
  if (d == 0LL) {
	  cout << ((double) m - 1) / n << endl;
	} else {
	  cout << 2.0 * (m - 1) * max(0LL, n - d) / (n * n) << endl;
	}
  return 0;
}
