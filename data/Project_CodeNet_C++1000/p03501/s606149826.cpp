#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,N;
  cin >> N>>A>>B;
  int C = A * N; 
  if (C == B) {
    cout << C << endl;
  }
  else if (C > B) {
    cout << B << endl;
  }
  else {
    cout << C << endl;
return 0;
  }
}