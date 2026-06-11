#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long> a(N);
  long long maxN = 0;
  double halfN;
  for(int i = 0; i < N; ++i) {
    cin >> a[i];
    maxN = max(maxN, a[i]);
  }
  halfN = (double)maxN / 2.0;
  double dist = abs((double)a[0] - halfN);
  long long ans = a[0];
  for(int i = 0; i < N; ++i) {
    if(dist >= abs((double)a[i] - halfN)) {
      dist = abs((double)a[i] - halfN);
      ans = a[i];
    }
  }
  cout << maxN << " " << ans << endl;

  return 0;
}
