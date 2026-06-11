#include <bits/stdc++.h>
using namespace std;

int main() {
string s;
  cin >> s;
  if(s.at(0) == '1') s.at(0) = '9';
  else s.at(0) = '1';
  if(s.at(1) == '1') s.at(1) = '9';
  else s.at(1) = '1';
  if(s.at(2) == '1') s.at(2) = '9';
  else s.at(2) = '1';
  cout << s << endl;
}