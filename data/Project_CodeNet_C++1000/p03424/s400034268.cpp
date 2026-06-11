#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int n; cin >> n;
  string s;
  int a, b, c, d;
  a = b = c = d = 0;
  while(n--) {
    cin >> s;
    if(s == "P") a = 1;
    if(s == "W") b = 1;
    if(s == "G") c = 1;
    if(s == "Y") d = 1;
  }
  cout << (a+b+c+d == 4 ? "Four" : "Three") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
