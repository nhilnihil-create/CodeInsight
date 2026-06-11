#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s,t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());
  bool ok = false;
  rep(i,min(n,m)) {
    if(s[i] < t[i]) {
      ok = true;
      break;
    } else if(s[i] > t[i]) {
      break;
    }
    if (i == min(n, m)-1 && n < m) {
      ok = true;
      break;
    }
  }

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}