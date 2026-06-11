#include <bits/stdc++.h>
using namespace std;

main(){
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  bool ansis = false;
  for(int i=n-1; i>=m-1; --i){
    if(s[i] == '?' || s[i] == t[m-1]){
      ansis = true;
      for(int j=0; j<m; ++j){
        if(s[i-j] != '?' && s[i-j] != t[m-1-j]) ansis = false;
      }
      if(ansis){
        for(int j=0; j<m; ++j){
          s[i-j] = t[m-1-j];
        }
        break;
      }
    }
    if(ansis) break;
  }
  if(!ansis){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  for(int i=0; i<n; ++i){
    if(s[i] == '?') s[i] = 'a';
  }
  cout << s << endl;
}