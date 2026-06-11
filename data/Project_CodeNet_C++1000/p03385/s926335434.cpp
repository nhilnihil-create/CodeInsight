#include <bits/stdc++.h>
using namespace std;

int main() {
string s;
  cin >> s;
  if(s.at(0) == 'a' && s.at(1) == 'b' && s.at(2) == 'c') cout << "Yes" << endl;
  else if(s.at(0) == 'b' && s.at(1) == 'c' && s.at(2) == 'a') cout << "Yes" << endl;
  else if(s.at(0) == 'c' && s.at(1) == 'a' && s.at(2) == 'b') cout << "Yes" << endl;
  else if(s.at(0) == 'a' && s.at(1) == 'c' && s.at(2) == 'b') cout << "Yes" << endl;
  else if(s.at(0) == 'b' && s.at(1) == 'a' && s.at(2) == 'c') cout << "Yes" << endl;
  else if(s.at(0) == 'c' && s.at(1) == 'b' && s.at(2) == 'a') cout << "Yes" << endl;
  else cout << "No" << endl;
}
