#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d.at(i);
  bool fin = false;
  while (!fin) {
    fin = true;
    rep(i, n-1) {
      if (d.at(i) < d.at(i+1)) {
        fin = false;
        int temp = d.at(i);
        d.at(i) = d.at(i+1);
        d.at(i+1) = temp;
      }
    }
  }
  int x, ans = 0;
  rep(i, n) {
    if (i == 0 || x > d.at(i)) {
      x = d.at(i);
      ans++;
    }
  } 
  cout << ans << endl;
}
