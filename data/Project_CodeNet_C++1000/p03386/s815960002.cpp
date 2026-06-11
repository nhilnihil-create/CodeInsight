#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,K ;
  cin >> A >> B >> K;
 if ( B - A + 1 >= 2*K) {
  for (int i = 0; i < K; i++) {
  cout << A + i << endl;
    cout << endl;
  }
 }
   if ( B - A + 1 >= 2*K) {
  for (int i = 0; i < K; i++) {
  cout << B - (K - 1) + i  << endl;
    cout << endl;
  
  
 }
 }
   else {
    for (int i = 0; i < B - A + 1; i++) {
  cout << A + i << endl;
    cout << endl;
}

  }
   return 0;
  }
