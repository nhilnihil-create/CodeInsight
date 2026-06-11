#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t; cin >> s >> t;
  int ssize = s.size(), tsize = t.size();
  if(ssize < tsize){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  bool ok;
  bool done = false;
  for(int i = ssize - tsize; i >= 0; i--){
    ok = true;
    for(int j = 0; j < tsize; j++){
      if(s.at(i+j) != '?' && s.at(i+j) != t.at(j)) ok = false;
    }
    if(ok){
      done = true;
      for(int k = i; k < i + tsize; k++){
        s.at(k) = t.at(k-i);
      }
      break;
    }
    if(ok) break;
  }
  if(!done) cout << "UNRESTORABLE" << endl;
  else{
    for(int i = 0; i < ssize; i++){
      if(s.at(i) == '?') s.at(i) = 'a';
    }
    cout << s << endl;
  }
}
  