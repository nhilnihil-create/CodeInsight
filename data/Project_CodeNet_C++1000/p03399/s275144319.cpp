#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int sum = 0;
  if (a >= b) sum += b;
  else sum += a;

  if (c >= d) sum += d;
  else sum += c;

  cout << sum << endl;
}