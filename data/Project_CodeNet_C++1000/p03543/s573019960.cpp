#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D,N;
  cin >> N;
  D = N % 10;
  C = (N % 100 - D)/10;
  B = (N % 1000 - N % 100)/100;
  A = (N - N % 1000)/1000;
    
  if ((A == B && B == C) || (B==C && C == D) ) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}