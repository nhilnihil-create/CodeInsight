#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i + d <= n) cnt++;
    if (i - d >= 1 && d != 0) cnt++;
  }
  cout.precision(12);
  cout << (m - 1) * cnt / (double)n / n << endl;
}
