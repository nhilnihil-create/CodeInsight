#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  int ans_max = min(a, b);
  int ans_min = max(a + b - n, 0);

  cout << ans_max << " " << ans_min << endl;
  return 0;
}