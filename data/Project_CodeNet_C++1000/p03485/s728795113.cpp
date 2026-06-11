#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int sum = a + b;
  int x = sum / 2 + sum % 2;
  cout << x << endl;
}