#include <bits/stdc++.h>
using namespace std;

int main () {
  string s;
  cin >> s;

  int a=s[5]-'0',b=s[6]-'0';
  if (a==0 && b<=4)
    cout << "Heisei" << endl;
  else cout << "TBD" << endl;

  return 0;
}
