#include <bits/stdc++.h>
using namespace std;

int main() {
  string f, s;
  cin >> f >> s;
  
  bool ok = true;
  for(int i = 0; i < 3; i++){
    if(f.at(i) != s.at(2-i)) ok = false;
  }
  
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}