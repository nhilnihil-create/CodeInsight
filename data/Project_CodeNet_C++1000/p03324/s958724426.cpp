#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int D, N;
  cin >> D >> N;
  
  int A;
  
  if (N != 100) {
    A = N*pow(100,D);
  }
  else {
    A = 101*pow(100,D); 
  }
  
  cout << A << endl;
}
  
  
  