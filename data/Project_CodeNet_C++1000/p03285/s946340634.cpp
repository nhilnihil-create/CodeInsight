#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  bool can = false;
  for(int i=0; ; i++) {
    if(7*i > n) {
      break;
    }
    for(int j=0; ; j++) {
      if(7*i+4*j == n) {
        can = true;
        break;
      }
      else if(7*i+4*j > n) break; 
    }
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}