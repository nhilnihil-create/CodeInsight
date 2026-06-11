#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b;
  string s;
  cin >> a >> b >> s;
  
  for(int i = 0; i < s.size(); i++) {
    if(i == a) {
      if(s[i] != '-') {
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      if(s[i] == '-') {
        cout << "No" << endl;
        return 0;
      }
    }    
  }
  cout << "Yes" << endl;
}