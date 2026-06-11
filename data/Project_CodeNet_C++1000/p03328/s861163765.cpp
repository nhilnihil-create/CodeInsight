#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int tmp = B - A;
  int a = 0;
  while (--tmp) a += tmp;
  cout << a - A << "\n";
}