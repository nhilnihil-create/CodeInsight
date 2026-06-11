#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t,ans="Yes";
  cin >> s >> t;
  vector<long> a(26);
  vector<long> b(26);
  for(long i=0;i<s.size();i++) {
    if(a[t[i]-'a']!=0&&a[t[i]-'a']!=s[i]) ans="No";
    a[t[i]-'a']=s[i];
    if(b[s[i]-'a']!=0&&b[s[i]-'a']!=t[i]) ans="No";
    b[s[i]-'a']=t[i];
  }
  cout << ans << endl;
}