#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  int a, b;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    sum += a;
    if (i == 0)
      b = a;
    else if (b > a)
      b = a;
  }
  int ans = n + (x - sum) / b;

  cout << ans << endl;
}