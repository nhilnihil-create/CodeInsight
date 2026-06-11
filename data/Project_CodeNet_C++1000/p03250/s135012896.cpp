#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int X = max(max(A, B), C);
  cout << A + B + C + X * 9 << endl;
}
