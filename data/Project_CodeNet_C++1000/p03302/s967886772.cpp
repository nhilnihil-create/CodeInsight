#include <bits/stdc++.h>
using namespace std;

int main() {
  int s,t;
  cin >> s >> t;//.at(0) >> s.at(1) >> s.at(2) >> s.at(3);
  //sort(s.begin(),s.end());
  if(s+t==15) cout << '+' << endl;
  else if(s*t==15) cout << '*' << endl;
  else cout << 'x' << endl;
  return 0;
}