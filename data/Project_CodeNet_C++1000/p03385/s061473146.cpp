#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int A = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == 'a') {
      A++;
    }
  }
  int B = 0;
  for (int j = 0; j < S.size(); j++) {
    if (S.at(j) == 'b') {
      B++;
    }
  }
  int C = 0;
  for (int k = 0; k < S.size(); k++) {
    if (S.at(k) == 'c') {
     C++; 
    }
  }
  if (A == 1 && B == 1 && C == 1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
