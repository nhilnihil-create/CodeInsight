#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  string m = s.substr(5, 2);
  int mt = stoi(m);
  if(mt <= 4) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}