#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int m = n * (n - 1) / 2 - n/2;
  int val = 0;
  if(n % 2 == 0) val = n + 1;
  else val = n;
  cout << m << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if(i + j != val) cout << i << " " << j << '\n';
    }
  }
  return 0;
}