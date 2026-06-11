#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A + B == 15) cout << "+" << endl;
  else if (A * B == 15) cout << "*" << endl;
  else cout << "x" << endl;
}