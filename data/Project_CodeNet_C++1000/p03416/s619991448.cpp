#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;

  int C = 0;
  
  for (int i = A; i < B + 1; i++) {
    if (i % 10001 % 1010 != 1000 && i % 10001 % 1010 % 100 == 0) {
      C++;
    } 
  }   
  
  cout << C << endl;   

}