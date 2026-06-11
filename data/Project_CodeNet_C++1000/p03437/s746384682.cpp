#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, y, z;
  cin >> x >> y;
  
  bool exist = false;
  for(int i=1; i<=y; i++) {
    z = x*i;
    if(x%y==0) break;
    if(z%y!=0) {
      exist = true;
      break; 
    }
  }
  if(exist) cout << z << endl;
  else cout << -1 << endl;
  return 0;
}