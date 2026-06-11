#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main(){
  string s;
  cin >> s;
  int l = s.length();
  if(s[0] == '0' || s[l-1] == '1' || s[l-2] == '0') {
    cout << -1 << endl;
    return 0;
  }
  rep(i,l-1) {
    if(s[i] != s[l-2-i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int p = l;
  for(int i = l-2; i >= 0; i--) {
    cout << i+1 << " " << p << endl;
    if(s[i] == '1') p = i+1;
  }
  return 0;
}