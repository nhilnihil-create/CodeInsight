#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, d;
  cin>>n>>m>>d;
  long long a;
  if (d > 0) {
    a = (n - 2 * d) * 2 + 2 * d;
  } else {
    a = n;
  }
  double ans = 1.0 * (m - 1) * a / (n * n);
  printf("%.9lf\n", ans);
}