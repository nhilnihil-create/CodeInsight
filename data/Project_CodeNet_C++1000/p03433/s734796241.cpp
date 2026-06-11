#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, A; // N=payment, A=number of 1-yen coins
  int Residue;
  
  cin >> N;
  cin >> A;
  Residue = N % 500;
  
  if (A >= Residue) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
