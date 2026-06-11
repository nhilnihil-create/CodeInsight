#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  
  string x;
  int ans = 0;
  for(int i=stoi(s); i<=stoi(t); i++) {
    x = to_string(i);
    if(x[0]==x[4] && x[1]==x[3]) ans++;
  }
  cout << ans << endl;
  return 0;
}