#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  for(int i = 0; i < s.size(); i++) {
    if(i == 3) cout << "8";
    else cout << s[i];
  }
  cout << endl;
}