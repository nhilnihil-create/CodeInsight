#include <bits/stdc++.h>
using namespace std;

int main() {  
  int n, r = 0;
  string s;
  cin >> n >> s;
  for(int i = 0; i < (int)s.size(); i++) {
    if(s[i] == 'R') r++;
  }
  cout << ( r > n-r ?"Yes" :"No") << "\n";
}