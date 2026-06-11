#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  int t, a; cin >> t >> a;
  vector<int> h(n);
  for (int i=0; i<n; i++) cin >> h.at(i);
  
  int ans_id = -1;
  double ans_va = 1000000;
  double tmp;
  for (int i=0; i<n; i++) {
    tmp = t - h[i] * 0.006;
    if (abs(a - tmp) < ans_va) {
      ans_va = abs(a - tmp);
      ans_id = i;
    }
  }
  
  cout << ans_id + 1 << endl;
  return 0;
}