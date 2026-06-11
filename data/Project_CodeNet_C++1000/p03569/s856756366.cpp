#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s, t;
  cin >> s;
  t = s;
  reverse(rng(t));
  int ans = 0;
  if(s==t) {
    cout << ans << endl;
    return 0;
  }
  int i = 0, j = 0;
  while(j < s.size()) {
    if(s[i]==t[j]) {
      i++; j++;
    }
    else if(s[i]=='x') i++;
    else if(t[j]=='x') {//sに挿入するxの数だけ数えればよい
      j++;
      ans++;
    }
    else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}