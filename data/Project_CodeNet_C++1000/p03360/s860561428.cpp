#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int k;
  cin >> k;
  int m = max(a, max(b, c));
  int s = (a + b + c) - m;
  for (int i = 0; i < k; i++) {
    m *= 2;
  }
  cout << s + m << endl;
  return 0;
}