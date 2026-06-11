#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  vector<long> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  vector DP(41, vector(2, -1L));
  DP.at(0).at(0) = 0;
  for (int i = 0; i < 40; i++) {
    int ri = 40 - i - 1;
    long mask = 1LL << ri;
    int cnt = 0;
    for (auto a : A) if (a & mask) cnt++;
    long c0 = cnt * mask;
    long c1 = (N - cnt) * mask;
    if (DP.at(i).at(1) != -1) {
      DP.at(i + 1).at(1) = max(DP.at(i + 1).at(1), DP.at(i).at(1) + max(c0, c1));
    }
    if (DP.at(i).at(0) != -1) {
      if (K & mask) DP.at(i + 1).at(1) = max(DP.at(i + 1).at(1), DP.at(i).at(0) + c0);
    }
    if (DP.at(i).at(0) != -1) {
      if (K & mask) DP.at(i + 1).at(0) = max(DP.at(i + 1).at(0), DP.at(i).at(0) + c1);
      else DP.at(i + 1).at(0) = max(DP.at(i + 1).at(0), DP.at(i).at(0) + c0);
    }
  }
  cout << max(DP.at(40).at(0), DP.at(40).at(1)) << "\n";
}