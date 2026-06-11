#include <bits/stdc++.h>
using namespace std;

int main() {
  int A , B , C , D , E , F , G , H , J , K;
  cin >> A >> B;
  C = B - A + 1;
  //D = A;
  K = 0;
  for ( int i = 0; i < C; i++ ){
     E = A / 10000;
     F = ( A - E * 10000 ) / 1000;
     G = ( A - E * 10000 -  F * 1000 ) / 100;
     H = ( A - E * 10000 -  F * 1000 - G * 100 ) / 10;
     J = A - E * 10000 -  F * 1000 - G * 100 - H * 10;
    if ( E * 10000 +  F * 1000 + G * 100 + H * 10 + J == J * 10000 + H * 1000 + G * 100 + F * 10 + E ){
      K = K + 1;
    }
    A = A + 1;
  }
  cout << K << endl;
}