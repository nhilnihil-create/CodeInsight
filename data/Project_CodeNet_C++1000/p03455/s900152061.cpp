#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ab = a * b % 2;
  cout << (ab == 0 ? "Even" : "Odd") << endl;
}