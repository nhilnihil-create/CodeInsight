#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  int d = b - a;
  int tou = d * (d + 1) / 2;
  cout << tou - b << endl;
  return 0;
}