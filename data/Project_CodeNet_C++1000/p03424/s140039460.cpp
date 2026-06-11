#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a;
  string s;
  a=0;
  cin >> n;
  for(i=0;i<n;i++) {
    cin >> s;
      if(s == "Y") {
        a++;
        break;
      }
  }
  if(a == 0) {
    cout << "Three" << endl;
  }
  else {
    cout << "Four" << endl;
  }
  return 0;
}
        
