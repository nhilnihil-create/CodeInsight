#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;
  
  if(A == B)
    cout << 2*A << endl;
  else if(A > B)
    cout << 2*A - 1 << endl;
  else
    cout << 2*B - 1 << endl;
  
  return 0;
}