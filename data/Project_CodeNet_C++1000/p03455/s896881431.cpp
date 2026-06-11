#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int C = A * B;
  
  if ( C % 2 == 0 ) {
    cout << "Even"; }
  else {
    cout << "Odd"; }
}