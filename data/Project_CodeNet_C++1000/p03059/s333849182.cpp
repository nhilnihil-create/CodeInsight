#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int T = (C - C % A) / A;
  cout << T * B << endl;
}
