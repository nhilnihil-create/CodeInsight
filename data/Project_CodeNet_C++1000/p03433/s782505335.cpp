#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  
  if (A == 0) {
    if (N % 500 == 0) {
      cout << "Yes"<< endl; 
    }
    else {
      cout << "No" << endl; 
    }
    return 0;
  }
  if (N <= A) {
    cout << "Yes" << endl;
    return 0;
  }
  // N > A && A > 0
  int modulo = N % 500;
  if (modulo > A) cout << "No" << endl;
  else cout << "Yes" << endl;
}