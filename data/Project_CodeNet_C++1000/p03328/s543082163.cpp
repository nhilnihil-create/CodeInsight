#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, l, m;
  cin >> a >> b;
  
  l = b - a;
  for (int i = 0; i <= l; i++) m = m + i;
  
  cout << m - b << endl;
}