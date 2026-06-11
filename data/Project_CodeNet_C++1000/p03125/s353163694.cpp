#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long llong;

int main() {
  int a, b;
  cin >> a >> b;
  if (b % a)
    cout << b - a << endl;
  else
    cout << a + b << endl;

  return 0;
}