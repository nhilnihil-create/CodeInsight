#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, PA, PB;
  cin >> N >> A >> B;
  PA = N * A ;
  PB = B ;
  
  if ( PA == PB ) {
    cout << PA << endl;
  }
  if ( PA < PB ) {
    cout << PA << endl;
  }
  if ( PA > PB ) {
    cout << PB << endl;
  }
}