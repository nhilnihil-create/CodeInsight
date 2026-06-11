#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n;
  char s;
  cin >> n;
  bool flag = 0;
  for(int i = 0; i < n; i++) {
    cin >> s;
    if(s == 'Y') flag = 1;
  }
  
  if(flag) cout << "Four" << endl;
  else cout << "Three" << endl;
}