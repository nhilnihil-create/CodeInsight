#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  
  if (N <= A) {
    cout << "Yes" << endl;
    return 0;
  }
  // N > A 
  int modulo = N % 500;
  if (modulo > A) cout << "No" << endl;
  else cout << "Yes" << endl;
}