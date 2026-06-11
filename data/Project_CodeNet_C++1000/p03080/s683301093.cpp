#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  int cntR = 0, cntB = 0;
  rep(i, s.size()) {
    if(s[i] == 'R') cntR++;
    else cntB++;
  }

  bool flag = false;
  if(cntR > cntB) flag = true;

  cout << (flag ? "Yes" : "No") << '\n';
  return 0;
}
