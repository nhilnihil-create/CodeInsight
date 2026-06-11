#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, P;
  cin >> A >> P;

  cout << P / 2 + (P % 2 + A * 3) / 2 << endl;
}
