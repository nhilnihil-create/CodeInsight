#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,S,H,J,I;
  cin >> N; 
   S = N / 1000;
   N = N % 1000;
   H = N / 100;
   N = N % 100;
   J = N / 10;
   I = N % 10;
  if (S == H && H == J ) {
    cout << "Yes" << endl;
   }
  else if (H ==J && J == I) {
    cout <<  "Yes" << endl;
   }
  else {
    cout << "No" << endl;
   }
}