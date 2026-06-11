#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N = 0, A = 0, B = 0;
  
  cin >> N >> A >> B;
  
  int def = (N * A) - B;
  
  if (def >= 0){
  cout << B << endl;
  }
  else{
  cout << N * A << endl;
  }
  
}