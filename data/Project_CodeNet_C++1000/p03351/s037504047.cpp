#include <bits/stdc++.h> 
using namespace std;

int main() {

  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  bool ans = false;
  
  if (a-c <= d && c-a <= d) ans = true;
  else if (a-b <= d && b-a <= d) {
    if (b-c <= d && c-b <= d) ans = true;
  }
  
  cout << ((ans) ? "Yes" : "No") << endl;
  
}