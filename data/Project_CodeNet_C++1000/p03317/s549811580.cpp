#include <bits/stdc++.h>
using namespace std;

int main(int, char**) {
  int N, K;
  cin >> N >> K;

  cout << (1 + (N - K) / (K - 1) + ((N-K) % (K-1) !=0)) << endl;

  // vector<int> nums;
  // nums.resize(N);
  // for (int i = 0; i < N; i++) {
  //   cin >> nums[i];
  // }

  return 0;
}
