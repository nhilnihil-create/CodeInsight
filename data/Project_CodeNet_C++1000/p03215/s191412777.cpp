#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long N, K;
  cin >> N >> K;
  vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<long long> sum;
  for (int i = 0; i < N; i++) {
    sum.push_back(a[i]);
    for (int j = i + 1; j < N; j++) {
      sum.push_back(sum.back() + a[j]);
    }
  }

  vector<bool> ok((N * (N + 1)) / 2, true);
  long long ans = 0;
  for (int i = 63; i >= 0; i--) {
    long long cnt = 0;
    vector<int> tmp;
    for (long long j = 0, end = (N * (N + 1) / 2); j < end; j++) {
      if (!ok[j]) continue;
      if (sum[j] & (1LL << i))
        cnt++;
      else
        tmp.push_back(j);
    }
    if (cnt >= K) {
      ans |= (1LL << i);
      for (auto t : tmp) ok[t] = false;
    }
  }
  cout << ans << endl;
  return 0;
}