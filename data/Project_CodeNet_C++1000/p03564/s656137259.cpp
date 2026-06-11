#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  long long res = 1LL<<60;
  for (int i = 0; i <= N; ++i) {
    long long val = (1LL<<i) + K * (N-i);
   	res = min(res, val);
  }
  cout << res << endl;
}