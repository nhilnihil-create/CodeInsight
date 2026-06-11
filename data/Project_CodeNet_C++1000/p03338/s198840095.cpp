#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int size = s.size()-1;
  string t,u;
  int count,ans=0;
  for(int i=1; i<n; i++) {
    count = 0;
    t = s.substr(0,i);
    u = s.substr(i,size);
    for(int j=0; j<26; j++) {
      if(t.find('a'+j) != ::string::npos && u.find('a'+j) != ::string::npos) {
        count++;
      }
    }
    ans = max(ans,count);
  }
  cout << ans << endl;
}