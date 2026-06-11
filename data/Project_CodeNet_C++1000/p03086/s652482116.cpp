#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  vector<int> len(s.size());
  int cnt = 0;
  rep(i,s.size()) {
    if (s[i] == 'A' || s[i] == 'G' || s[i] == 'T' || s[i] == 'C') {
      cnt++;
      len[i] = cnt;
    }
    else {
      cnt = 0;
      len[i] = 0;
    } 
  }
  int ans = 0;
  rep(i,s.size()) ans = max(ans, len[i]);
  cout << ans << endl;
  return 0;
}