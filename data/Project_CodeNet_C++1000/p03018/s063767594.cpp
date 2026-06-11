#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  string s, t = "";
  cin >> s;
  int i = 0, sz = s.size();
  while(i < sz-1) {
    if(s[i]=='B'&&s[i+1]=='C') {
      t += 'D';
      i++;
    }
    else t += s[i];
    i++;
  }
  ll ans = 0, num = 0;
  int tz = t.size();
  for(int i = 0; i < tz; i++) {
    if(t[i]=='A') num++;
    else if(t[i]=='D') ans += num;
    else num = 0;
  }
  cout << ans << endl;
  return 0;
}