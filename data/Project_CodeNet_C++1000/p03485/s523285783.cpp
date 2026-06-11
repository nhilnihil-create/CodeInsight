#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  a += b;
  cout << ((a % 2) ? a / 2 + 1 : a / 2) << "\n";
}