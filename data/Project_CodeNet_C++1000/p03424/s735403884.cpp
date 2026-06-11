#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int cntg = 0;
  int cntp = 0;
  int cnty = 0;
  int cntw = 0;
  cin >> n ;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "G") {
      cntg = 1;
    }
    else if (s == "Y") {
      cnty = 1;
    }
    else if (s == "P") {
      cntp = 1;
    } 
    else {
      cntw = 1;
    }
  }
  int res = cntg + cntw + cnty + cntp;
  if (res == 1) {
    cout << "One" << endl;  
  }
  else if (res == 2) {
    cout << "Two" << endl;  
  }
  else if (res == 3) {
    cout << "Three" << endl;  
  }
  else if (res == 4) {
    cout << "Four" << endl;  
  }
 
}