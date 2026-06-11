#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C, D;
  cin >> A >> B;
  C = A + B;
  D = A * B;
  if(C == 15) {
    cout << "+" << endl;
  }
  else if(D == 15) {
    cout << "*" << endl;
  }
  else {
    cout << "x" << endl;
  }
}