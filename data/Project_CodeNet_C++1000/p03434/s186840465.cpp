#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  bool fin = false;
  while (!fin) {
    fin = true;
    rep(i, n-1) {
      if (a.at(i) < a.at(i+1)) {
        fin = false;
        int temp = a.at(i);
        a.at(i) = a.at(i+1);
        a.at(i+1) = temp;
      }
    }
  }
  int ans = 0;
  rep(i, n) if (!(i % 2)) ans += a.at(i);
  rep(i, n) if ( (i % 2)) ans -= a.at(i);
  cout << ans << endl;
}
