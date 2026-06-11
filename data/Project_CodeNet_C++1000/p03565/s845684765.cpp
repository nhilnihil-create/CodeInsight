#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  string s, t;cin>>s>>t;
  reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
  bool can = false;
  int i;
  for(i = 0; i < s.size(); i++) {
    if(s[i] == t[0] || s[i] == '?'){
      can = true;
      Fr(j, t.size()-1) {
        if(i+j >=s.size()) {
          can = false;
          break;
        }
        if(s[i+j] != t[j] && s[i+j] != '?') can = false; 
      }
    }
    if(can) break;
  }
  if(can) {
  for(int j = 0; j < t.size(); j++) s[j+i] = t[j];
  for(int j = 0; j < s.size(); j++) if(s[j] == '?')s[j] = 'a';
  reverse(s.begin(), s.end());
  cout << s << endl;
  } else cout << "UNRESTORABLE" << endl;
  return 0;
}
