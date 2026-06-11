#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  int x = 0, y = 0, time = 0;
  bool ok = true;
  rep(i,n) {
    int t,tmpx, tmpy;
    cin >> t >> tmpx >> tmpy;
    time = t - time;
    x = abs(tmpx - x);
    y = abs(tmpy - y);
    if (time >= x+y && time%2==(x+y)%2) {
      ok = true;
    } else {
      ok = false;
      cout << "No" << endl;
      return 0;
    }
  }
  if (ok) cout << "Yes" << endl;
  return 0;
}