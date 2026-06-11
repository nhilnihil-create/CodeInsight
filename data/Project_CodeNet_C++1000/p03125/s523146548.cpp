#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  if (b % a == 0) {
    cout << b + a;
  }
  else {
    cout << b - a;
  }

  return 0;

}