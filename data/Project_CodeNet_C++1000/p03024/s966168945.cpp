#include <bits/stdc++.h>
using namespace std;
int main(void){
  int i,x=0;
  string s;
  cin >> s;
  for (i=0;i<s.size();i++) if (s.at(i)=='x') x++;
  if (x<8) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}