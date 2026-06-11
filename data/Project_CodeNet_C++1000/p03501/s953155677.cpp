#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, x;
  cin >> N >> A >> B;
  if (A*N>B) {
    x = B;
    cout << x << endl;
  }
    else if (A*N==B) {
      x = B;
      cout << x << endl;
    }
  else {
      x=A*N;
      cout << x << endl;
    }
}