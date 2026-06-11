#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  bool ans = true;
  if(s.at(5) == '1') ans = false;
  int k = s.at(6) - '0';
  if(k > 4) ans = false;
  
  if(ans) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}