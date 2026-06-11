#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
  fastIO;

  int n;
  cin >> n;
  vector<int> V(n), C(n);
  rep(i, n) cin >> V.at(i);
  rep(i, n) cin >> C.at(i);

  int maxValue = 0;
  for(int bit=0; bit<(1<<n); ++bit) {
    int subsum = 0;
    for(int i=0; i<n; ++i) {
      if(bit & (1 << i) ) {
        subsum += V.at(i) - C.at(i);
      }
    }
    maxValue = max(subsum, maxValue);
  }

  cout << maxValue << endl;
}
