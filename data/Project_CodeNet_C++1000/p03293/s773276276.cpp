#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t; cin >> s >> t;
  bool ok = false;
  for(int i = 0; i < s.size(); i++){
    char c = s.at(s.size()-1);
    s.pop_back();
    s = c + s;
    if(s == t){
      ok = true;
      break;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}