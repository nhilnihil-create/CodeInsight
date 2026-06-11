#include <bits/stdc++.h>
using namespace std;
using lint  = long long;

signed main(){
  string s; cin >> s;
  lint ans = 0;
  lint l = 0, r = s.size() - 1;
  while(l < r){
    if(s[l] == s[r]) l++, r--;
    else if(s[l] == 'x' && s[r] != 'x'){
      l++; ans++;
    }
    else if(s[l] != 'x' && s[r] == 'x'){
      r--; ans++;
    }
    else{
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}