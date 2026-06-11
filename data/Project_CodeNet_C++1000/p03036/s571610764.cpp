#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int r, D, x;
  cin >> r >> D >> x;
  int s;
  s = r*x - D;
  
  cout << s << endl;
  
  for (int i = 0; i < 9; i++){
    s = r*s - D;
    cout << s << endl;
  }
    
  
}