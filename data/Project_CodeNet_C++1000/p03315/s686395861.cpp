#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  string s;
  cin >> s;
  char a[s.size()];
  for(int i=0; i<s.size(); i++) {
    a[i]=s.at(i);
  }
  int ans=0;
  for(int i=0; i<s.size(); i++) {
    if(a[i]=='+') {
      ans++;
    }
    else {
      ans--;
    }
  }
  cout << ans << endl;
}