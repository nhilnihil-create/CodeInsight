#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  vector<int> x(3);
  x[0] = a+b;
  x[1] = a*b;
  x[2] = a-b;
  sort(x.begin(), x.end());
  cout << x[2] << endl;
}