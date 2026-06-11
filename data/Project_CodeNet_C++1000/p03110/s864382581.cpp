#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  double ans;
  for (int i=0; i<n; i++) {
    double x; string u;
    cin >> x >> u;
    if (u == "JPY") {
      ans += x;
    } else {
	  ans += x * 380000;
    }
  }
  cout << ans << endl;
  return 0;
}
