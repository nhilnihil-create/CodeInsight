#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  string s;
  cin >> s;
  
  bool ans = false;
  
  if (s[0] != s[1] && s[1] != s[2] && s[2] != s[0])
    ans = true;

  cout << ((ans) ? "Yes" : "No") << endl;
   
}