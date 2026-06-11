#include <bits/stdc++.h> 
using namespace std;

int main() {

  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  bool ans = false;
  
  if (abs(a-c) <= d) ans = true;
  else if (abs(a-b) <= d) {
    if (abs(b-c) <= d) ans = true;
  }
  
  cout << ((ans) ? "Yes" : "No") << endl;
  
}