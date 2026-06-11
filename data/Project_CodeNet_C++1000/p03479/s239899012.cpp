#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long x, y;
  cin >> x >> y;
  // x * 2^n <= y
  long long i;
  y /= x; 
  for (i = 1; ((long long)(1)<<i) <= y; ++i);
  cout << i << endl;

  return 0;
}

