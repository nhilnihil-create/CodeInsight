#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  
  bool ok = false;
  char f = n.at(1), s = n.at(2);
  if(n.at(0) == f && n.at(2) == f) ok = true;
  if(n.at(1) == s && n.at(3) == s) ok = true;
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}