#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  if (S[A] != '-') {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < A; i++) {
    if (!(S[i] >= '0' && S[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    } 
  }
  for (int i = A + 1; i <= A + B; i++) {
    if (!(S[i] >= '0' && S[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    } 
  }  
  cout << "Yes" << endl;
}