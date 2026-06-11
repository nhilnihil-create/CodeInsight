#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int m = max({(a + b), (a - b), (a * b)});
  cout << m << endl;
  return 0;
}