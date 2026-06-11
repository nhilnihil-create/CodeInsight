#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n;
  cin >> d >> n;
  cout << (n+n/100)*(int)pow(100, d);
  return 0;
}