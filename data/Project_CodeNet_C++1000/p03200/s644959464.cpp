#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  int len = s.size();
  
  int ordered = 0;
  bool out = false;
  ll int ans = 0;
  rep(i, len) {
    char x = s[i];
    if(!out) {
      if(x == 'B') out = true;
      else ++ordered;
    }
    
    if(out && x=='W') {
      ans = ans + i - ordered;
      ++ordered;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
