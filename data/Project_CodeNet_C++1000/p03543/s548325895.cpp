#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  int A = N / 1000;
  int B = (N % 1000) / 100;
  int C = (N % 100) / 10;
  int D = N % 10;
 
  if ( B == C && (A == B || C == D) ) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}