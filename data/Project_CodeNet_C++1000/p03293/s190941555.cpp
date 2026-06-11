#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s, t;
  cin >> s >> t;
  int sl = s.size();
  bool ok = false;
  rep(i, sl) {
    if(s == t) ok = true;
    s = s.back() + s.substr(0, sl-1);
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
    