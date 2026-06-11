#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  int t, a;
  cin >> t >> a;
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);

  double near_diff = 100000;
  int near_point = -1;

  for (int i = 0; i < n; i++) {
    double mean = t - h.at(i) * 0.006;
    double diff = abs(a - mean);
    if (near_diff > diff) {
      near_diff = diff;
      near_point = i + 1;
    }
  }

  cout << near_point << endl;
  return 0;
}