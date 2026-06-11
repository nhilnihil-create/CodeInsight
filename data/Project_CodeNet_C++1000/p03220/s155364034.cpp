#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,T,A;
  cin >> N >> T >> A;
  int h;
  int near = 1<<30;
  int ans = 0;
  for (int i=1; i <N+1; i++) {
    cin >> h;
    int d = (1000*T-h*6)-1000*A;
    if (d<0) d=-d;
    if (d < near) {
      near = d;
      ans = i;
    }
  }
  cout << ans  << endl;
}