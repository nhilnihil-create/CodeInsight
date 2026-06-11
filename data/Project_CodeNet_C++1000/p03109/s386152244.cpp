#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int y=0, m=0, d=0;
  for (int i=0; i<4; i++) {
    y+=(S[i]-'0')*pow(10,3-i);
  }
  for (int i=0; i<2; i++) {
    m+=(S[i+5]-'0')*pow(10,1-i);
  }
  
  string ans="TBD";
  if (y<2019) {
    ans="Heisei";
  }
  else if (y==2019) {
    if (m<=4) {
      ans="Heisei";
    }
  }
  cout << ans << endl;
}

