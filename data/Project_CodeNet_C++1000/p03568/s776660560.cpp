#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, even = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 0) even++;
  }

  if (even == 0)
    cout << pow(3, n) - 1;
  else
    cout << pow(3, n) - pow(2, even);

  return 0;
}