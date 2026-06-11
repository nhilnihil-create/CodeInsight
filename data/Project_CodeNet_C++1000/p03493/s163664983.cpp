#include<bits/stdc++.h>
using namespace std;
 
int main(void) {
  string s;
  cin >> s;
  
  int n = 0;
  
  for(int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      n += 1;
    } else {
      continue;
    }
  }
  cout << n << endl;
  return 0;
}