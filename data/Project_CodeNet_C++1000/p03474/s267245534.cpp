#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, K;
  string S;
  cin >> A >> B >> S;
  K=0;
  for (int i=0; i<A; i++) {
    if (S.at(i)!='-') {
      K=K+1;
    }
  }
  if (S.at(A)=='-') {
    K=K+1;
  }
  for (int j=A+1; j<A+B+1; j++) {
    if (S.at(j)!='-') {
      K=K+1;
    }
  }
  if (K==A+B+1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}