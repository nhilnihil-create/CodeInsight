#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string S;
  cin >> S;

  if (S == "keyence" || S.substr(0,7) == "keyence" || S.substr(S.size()-7,7) == "keyence") {
    cout << "YES" << endl;
    return 0;
  }

  vector<vector<string>> v = {
    {"k", "eyence"},
    {"ke", "yence"},
    {"key", "ence"},
    {"keye", "nce"},
    {"keyen", "ce"},
    {"keyenc", "e"},
  };

  string ans = "NO";
  rep(i,0,v.size()-1) {
    string l = v[i][0];
    string r = v[i][1];
    bool lok = false, rok = false;
    if (S.substr(0,l.size()) == l && S.substr(S.size()-r.size(),r.size()) == r) {
      ans = "YES";
    }
  }

  cout << ans << endl;
  return 0;
}
