#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  string S; ll K;
  cin >> S >> K;

  char ans = '0';
  if (K < 100) {
    bool all_one = true;
    rep(i,0,K-1) {
      if (S[i] != '1') all_one = false;
    }
    if (all_one) ans = '1';
  }
  if (ans == '0') {
    for (char c : S) {
      if (c != '1') {
        ans = c;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
