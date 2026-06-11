#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
  string s; cin >> s;
  int n = s.size();

  int ans1 = 0;
  int ans2 = 0;
  rep(i,n) {
    int c = s[i] - '0';
    if(c == i%2) ans1++;
  }
  rep(i,n) {
    int c = s[i] - '0';
    if(c != i%2) ans2++;
  }
  cout << min(ans1, ans2) << endl;
}