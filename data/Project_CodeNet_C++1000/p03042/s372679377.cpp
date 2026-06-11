#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool p = ((s[0] - '0') * 10 + (s[1] - '0') <= 12 && (s[0] - '0') * 10 + (s[1] - '0') > 0);
  bool q = ((s[2] - '0') * 10 + (s[3] - '0') <= 12 && (s[2] - '0') * 10 + (s[3] - '0') > 0);
  if(p && q) cout << "AMBIGUOUS" << endl;
  else if(p == true && q == false) cout << "MMYY" << endl;
  else if(p == false && q == true) cout << "YYMM" << endl;
  else cout << "NA" << endl;
}
