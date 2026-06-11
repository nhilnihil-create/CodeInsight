#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S;
  cin >> S;
  
  int p = 700;
  
  if (S.at(0)=='o') {
    p += 100;    
  }
  if (S.at(1)=='o') {
    p += 100;    
  }
  if (S.at(2)=='o') {
    p += 100;    
  }
  
  cout << p << endl;   

return 0;
}