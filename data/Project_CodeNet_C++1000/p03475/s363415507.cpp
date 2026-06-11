#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> c(n-1), s(n-1), f(n-1);
  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];

  rep(i,n-1) {
    int t = 0;
    rep(j,n-i-1) {
      if (t < s[i+j]) {
        t = s[i+j];
      } else if (t%f[i+j] == 0) {
        ;
      } else {
        t += f[i+j] - (t%f[i+j]);
      }
      t += c[i+j];
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}