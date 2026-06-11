#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  bool b = true;
  for(int i = 0; i < A; i++) {
    if(S.at(i) == '-') {
      b = false;
    }
  }
  if(S.at(A) != '-') {
    b = false;
  }
  for(int i = A + 1; i < A + B + 1; i++) {
    if(S.at(i) == '-') {
      b = false;
    }
  }
  if(b) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}