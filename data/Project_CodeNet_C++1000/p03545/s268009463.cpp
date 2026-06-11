#include <bits/stdc++.h>
#include <vector>
#include <bitset>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int bit = 0;
  while(!(bit & 8)) {
    int thisans = s[0]-48;
    rep(i, 3) {
      if(bit & (1<<i)) thisans += s[i+1] - 48;
      else thisans = thisans - (s[i+1] - 48);
    }
    if(thisans == 7) break;
    ++bit;
  }
  
  rep(i, 3) {
    cout << s[i] - 48;
    if(bit & (1<<i)) cout << "+";
    else cout << "-";
  }
  cout << s[3] - 48 << "=7" << endl;
  return 0;
}
