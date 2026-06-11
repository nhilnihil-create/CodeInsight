#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
  int sum = 0;
  
  if (A <= B) sum += A;

  else sum += B;
 
  if (C <= D) sum += C;

  else sum += D;
  
  cout << sum << endl;
}
