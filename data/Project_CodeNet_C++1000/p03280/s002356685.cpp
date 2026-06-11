#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, yard;
  cin >> x >> y;

  yard = (x * y) - (x + y) + 1;

  cout << yard << endl;
}