#include <bits/stdc++.h>
using namespace std;

int main() {
  int S ;
  cin >> S ;
  int H , J , I ;
  H = S / 100 ;
  S = S % 100 ;
  J = S / 10 ;
  S = S % 10 ;
  I = S / 1 ;
  cout << H + J + I << endl;
}