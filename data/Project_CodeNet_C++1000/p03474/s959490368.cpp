#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B;
  string S;
  cin >> A >> B;
  cin >> S;

  int l = A + B + 1;
  if(S.length() != l) {
    cout << "No" << endl;
    return 0;
  }

  if(S[A] != '-') {
    cout << "No" << endl;
    return 0;
  }

  char num[10];
  for(int i=0; i<=9; i++) {
    sprintf(&num[i], "%d", i);
  }

  for(int i=0; i<l; i++) {
    if(i == A) continue;
    bool check = false;
    for(int j=0; j<=9; j++) {
      if(S[i] == num[j]) {
        check = true;
      }
    }
    if(!check) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}