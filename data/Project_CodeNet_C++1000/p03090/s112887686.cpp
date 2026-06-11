#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int skip;
  if (n & 1)
    skip = n;
  else
    skip = n + 1;
  int ans = n * (n - 1) / 2 - n / 2;
  cout << ans << endl;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      if (i + j == skip) continue;
      printf("%d %d\n", i, j);
    }
}
