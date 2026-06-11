#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  string s; cin >> s;
  while(s.size() < 15) s += 'o';
  int win = 0;
  rep(i,15) {
    if(s[i]=='o') win++;
  }
  if(win>=8) puts ("YES");
  else puts ("NO");

  return 0;
}
