#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  long long s = 0;
  cin >> n >> k;
  for (int b = k + 1; b <= n; b++) {
    s += (b - k) * (n / b) + max(0, n % b - k + (k ? 1 : 0));
  }
  cout << s;
}