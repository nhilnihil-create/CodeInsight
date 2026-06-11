#include <bits/stdc++.h>
using namespace std;

long long a, b, c, k;

int main() {
  cin >> a >> b >> c >> k;
  if (k & 1)
    cout << b - a << endl;
  else
    cout << a - b << endl;
  return 0;
}
