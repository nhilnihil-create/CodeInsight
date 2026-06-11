#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  vector<int> H(N);
  for (int i=0; i<N; i++) cin >> H[i];
  double min=1000;
  int ans = 0;

  for (int i=0; i<N; i++) {
    if (min > abs(A-(T-H[i]*0.006))) {
      min = abs(A-(T-H[i]*0.006));
      ans = i+1;
    }
  }
  cout << ans << endl;
}