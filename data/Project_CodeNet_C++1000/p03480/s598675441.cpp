#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long ans;
  string s;
  cin >> s;
  ans=s.size()/2;
  while(ans!=s.size()) {
    if(s[ans]==s[s.size()-ans-1]&&(s[ans]==s[ans-1]||ans==s.size()/2)) {
      ans++;
    } else {
      break;
    }
  }
  cout << ans << endl;
}