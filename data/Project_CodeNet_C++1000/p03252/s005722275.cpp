#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  
  map<char, char> cs, ct;
  int l = s.size();
  bool ok = true;
  for(int i = 0; i < l; i++){
    char ns = s.at(i), nt = t.at(i);
    if(cs.count(ns)){
      if(cs.at(ns) != nt) ok = false;
    }
    else if(ct.count(nt)){
      if(ct.at(nt) != ns) ok = false;
    }
    else{
      cs[ns] = nt;
      ct[nt] = ns;
    }
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}