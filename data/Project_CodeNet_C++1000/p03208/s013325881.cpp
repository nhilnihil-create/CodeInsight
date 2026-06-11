#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int64_t> Hs(N);
  for (int n = 0; n < N; ++n) {
    cin >> Hs[n];
  }
  sort(Hs.begin(), Hs.end());
  
  int64_t mn = 1e9+1;
  for (int n = 0; n < N - K + 1; ++n) {
    mn = min(mn, Hs[n+K-1] - Hs[n]);
  }
  cout << mn << endl;
  
  return 0;
}
