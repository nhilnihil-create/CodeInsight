#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s; cin >> s;
  string m = "";
  for(ll i=0; i<s.size(); ++i){
    if(s[i] == '/'){
      for(ll j=1; s[i+j] != '/'; ++j){
        m += s[i+j];
      }
      break;
    }
  }
  string res = "Heisei";
  if(stoll(m) >= 5) res = "TBD";
  cout << res << endl;
  return 0;
}