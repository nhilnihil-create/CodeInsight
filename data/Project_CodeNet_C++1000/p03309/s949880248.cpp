#include <bits/stdc++.h>
using namespace std;

#define int long long

int N;
vector<int> A, B;

int calc(int b) {
  int ret = 0;
  for (int i = 1; i <= N; i++) {
    ret += abs(A[i-1] - (b + i));
  }
  return ret;
}

signed main() {
  cin >> N;
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = A[i] - (i + 1);
  }

  sort(B.begin(), B.end());

  cout << calc(B[N/2]) << endl;

  return 0;
}