#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, P;
  cin >> N >> A >> B;
  P = A * N ;
  if (P == B) cout << P << endl;
  else if (P > B) cout << B << endl;
  else cout << P << endl;
}