#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  double n, m, d, ans = 0;
  cin >> n >> m >> d;
  if (d == 0)
    ans = 1 / n;
  else
    ans = 2 * (n - d) / n / n;

  printf("%.20f", ans * (m - 1));
  return 0;
}
