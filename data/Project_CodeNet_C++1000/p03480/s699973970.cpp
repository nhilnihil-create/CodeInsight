#include <bits/stdc++.h>
         
using namespace std;

int main(){
  string s; cin >> s;
  int sz=s.size();
  int ans=sz;
  for(int i=1;i<sz;++i){
    if(s[i-1]!=s[i]) {
      ans=min(ans,max(i,sz-i));
    }
  }
  if(sz==1) ans=1;
  cout << ans << endl;
      
  return 0;
}
