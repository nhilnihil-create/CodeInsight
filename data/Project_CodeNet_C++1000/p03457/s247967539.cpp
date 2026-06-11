#include <bits/stdc++.h>
using namespace std;

bool check(int t,int x,int y) {
  if(x+y > t) {
      return false;
  }
  int d = (t-(x+y)) % 2;
  if(d != 0) {
    return false;
  }
  return true;
}
  
int main() {
  int n;
  cin >> n;
  int t0, x0, y0;
  cin >> t0 >> x0 >> y0;
  if(!check(t0, abs(x0), abs(y0))) {
    cout << "No" << endl;
    return 0;
  }
  for(int i=1; i<n; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    if(!check(t-t0, abs(x-x0), abs(y-y0))) {
      cout << "No" << endl;
      return 0;
    }
    t0 = t;
    x0 = x;
    y0 = y;
  }
  cout << "Yes" << endl;
}