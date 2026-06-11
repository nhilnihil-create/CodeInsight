#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(int i = 0; i < n; ++i)

void solve(void){
  int a, b; cin >> a >> b;
  string s; cin >> s;

  if ((int)s.size() != a + b + 1) {
    cout << "No" << endl;
    return;
  }

  if (s[a] != '-') {
    cout << "No" << endl;
    return;
  }

  rep((int)s.size(), i ){
    int t = s[i] - '0';
    if (i != a && (t < 0 || 9 < t)) {
      cout << "No" << endl;
      return ;
    }
  }

  cout << "Yes" << endl;
  return;
}

int main(void) {
  solve();
  return 0;
}