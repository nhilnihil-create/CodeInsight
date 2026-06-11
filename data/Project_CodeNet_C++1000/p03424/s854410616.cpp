#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  char x;
  bool ylw = false;
  for(int i=0; i<n; i++) {
    cin >> x;
    if(x=='Y') ylw = true;
  }
  if(ylw) cout << "Four" << endl;
  else cout << "Three" << endl;
  return 0;
}