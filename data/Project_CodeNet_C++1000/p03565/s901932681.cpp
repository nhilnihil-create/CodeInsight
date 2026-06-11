#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  string s,t;
  cin >> s;
  cin >> t;
  int n = s.length(), l = t.length();
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  bool ok = false;
  for(int i=0; i<n; i++){
    bool match = true;
    if(ok){
      if(s[i]=='?') s.replace(i, 1, "a");
      continue;
    }
    for(int j=0; j<l; j++){
      if(i+j>=n){
        match=false;
        continue;
      }
      if(s[j+i]=='?'||!match) continue;
      if(s[j+i]!=t[j]) match=false;
    }
    if(match){
      ok = true;
      s.replace(i, l, t);
    }
    if(s[i]=='?') s.replace(i, 1, "a");
  }
  reverse(s.begin(), s.end());
  if(ok) cout << s << endl;
  else cout << "UNRESTORABLE" << endl;
  return 0;
}
