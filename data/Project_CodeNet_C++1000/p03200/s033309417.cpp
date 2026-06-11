#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  int len = s.size();
  
  int black = 0;
  ll int ans = 0;
  rep(i, len) {
    char x = s[i];
    if(x == 'W') ans += black;
    else ++black;
  }
  
  cout << ans << endl;
  
  return 0;
}
