#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, d, nw = 0, cnt = 1;
  cin >> n;
  d = n;
  string ps, s;
  cout << 0 << endl;
  cin >> ps;
  while(s != "Vacant") {
    if(d % 4)
      d = (d / 4 + 1) * 2;
    else
      d /= 2;
    cout << (nw + d) % n << endl;
    cin >> s;
    cnt++;
    if(ps != s && s != "Vacant") {
      if(d == 2) {
        cout << (nw + 1) % n << endl;
        cin >> s;
        cnt++;
      }
    } else {
      nw = (nw + d) % n;
      ps = s;
    }
    if(cnt > 20) return 0;
  }
}