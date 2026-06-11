#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int n = 1;
  for(int i = 0;i < a;++i) {
    n = min(n * 2, n + b);
  }
  cout << n << endl;
}