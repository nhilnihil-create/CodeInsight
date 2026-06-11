#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int y, m, d;
      
  y = stoi(S.substr(0,4));
  m = stoi(S.substr(5,2));
  d = stoi(S.substr(8,2));
  
  string ans = "Heisei";
  if(y>=2020) ans = "TBD";
  else if (y==2019) {
    if(m>=5) ans = "TBD";
    else if(m==4 && d>30) {
      ans = "TBD";
    }
  }
  cout << ans << endl;

  return 0;
}
