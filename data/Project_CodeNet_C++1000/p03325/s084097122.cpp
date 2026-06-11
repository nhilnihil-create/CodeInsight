#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n;
  n = 0;
  while (cin >> a) while (!(a % 2)) a /= 2, n++;
  cout << n << "\n";
}