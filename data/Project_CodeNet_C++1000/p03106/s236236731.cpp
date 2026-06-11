#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K, C=0;
  cin >> A >> B >> K;
  for (int i=min(A,B); i>=1; i--) {
    if (A%i==0 && B%i==0) {C++;}
    if (C==K) {
      cout << i << endl;
      break;
    }
  }
}

