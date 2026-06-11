#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int l = 0, r = s.size()-1;
  int ans = 0;
  while(l<r){
    int xnum = 0;
    while(l<s.size()-1 && s[l] == 'x'){
      ++l;
      ++xnum;
    }
    while(r>0 && s[r] == 'x'){
      --r;
      --xnum;
    }
    if(s[l] != s[r]){
      cout << -1 << endl;
      return 0;
    }
    if(l<=r) ans += abs(xnum);
    ++l; --r;
  }
  cout << ans << endl;
}