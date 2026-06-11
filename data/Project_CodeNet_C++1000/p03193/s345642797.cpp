#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int64_t N, H, W, ans;
  cin >> N >> H >> W;
  ans=0;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  for (int64_t i=0; i<N; i++) {
    cin >> A[i] >> B[i];
  }
  for (int64_t j=0; j<N; j++) {
    if (A[j]>=H && B[j]>=W) {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}
