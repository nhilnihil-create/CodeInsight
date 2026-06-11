#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  int n = s.size();
  for(int i=0; i<26; ++i) for(int j=0; j<n; ++j){
    if(s[j] == 'a'+i){
      char cs = s[j], ct = t[j];
      for(int k=j; k<n; ++k){
        if(s[k] == cs && t[k] != ct){
          cout << "No" << endl;
          return 0;
        }
        if(t[k] == ct && s[k] != cs){
          cout << "No" << endl;
          return 0;
        }
      }
      break;
    }
  }
  cout << "Yes" << endl;
}