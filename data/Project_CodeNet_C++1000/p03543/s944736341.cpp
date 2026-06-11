#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B,C,D;
  cin >> N;
  
  A = N/1000;
  B = (N-A*1000)/100;
  C = (N-A*1000-B*100)/10;
  D = N-A*1000-B*100-C*10;
  
  if ((A==B && B==C) || (B==C && C==D)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}