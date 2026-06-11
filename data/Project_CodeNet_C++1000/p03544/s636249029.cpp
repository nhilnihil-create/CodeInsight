#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long int a=2, b=1;
  for (int i = 1; i<n; ++i) {
    long long int tmp = b;
    b = a + b;
    a = tmp;
  }
  cout << b << endl;
  return 0;
}