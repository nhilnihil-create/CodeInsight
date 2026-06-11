#include <bits/stdc++.h>
using namespace std;

int sum(int x) {
  int s = 0;
  while (x > 0) {
    s += x % 10;
    x /= 10;
  }
  return s;
}

int a = 1000000;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int j = n - i;
    int p = sum(i);
    int q = sum(j);
    if (p + q < a) a = p + q;
  }
  cout << a << endl;
    
}