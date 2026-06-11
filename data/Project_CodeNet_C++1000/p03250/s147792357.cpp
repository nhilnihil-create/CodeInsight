#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;

  int aa,bb,cc;
  aa= A * 10 + B + C;
  bb= A + B * 10 + C;
  cc= A  + B + C * 10;

  cout << max({aa,bb,cc}) << endl;
  return 0;
}
