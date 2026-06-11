#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,T;
  cin >> A >> T >> B;
 
  if (A * T > B ) {
    cout << B << endl;
  }
 
  if (A * T < B) {
    cout << A * T << endl;
  }
 
  if (A * T == B) {
    cout << A * T << endl;
  }
}