#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;

  cin >> a >> b;

  int soma = a + b;
  int sub = a - b;
  int mul = a * b;

  cout << max(max(soma, sub), mul) << endl;

  return 0;
}