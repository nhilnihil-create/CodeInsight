#include <bits/stdc++.h>
using namespace std;
main(){
  string s;
  cin >> s;
  sort(s.begin(),s.end());
  
  string t;
  cin >> t;
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  
  string ans;
  if(s<t) ans="Yes";
  else ans="No";
  
  
  cout << ans << endl;
}