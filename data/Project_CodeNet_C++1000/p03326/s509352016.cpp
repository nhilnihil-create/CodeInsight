#include <bits/stdc++.h>
using namespace std;

void solve(long long N, long long M, std::vector<long long> x,
           std::vector<long long> y, std::vector<long long> z) {

  long long sum = 0;
  long long ans = 0;
  for (int i = 0; i < 8; i++) {
    int a, b, c;
    a = (i & 1) ? -1 : 1;
    b = (i & 2) ? -1 : 1;
    c = (i & 4) ? -1 : 1;
    // cerr << a << ":" << b << ":" << c << endl;
    sum = 0;
    vector<long long> arr;

    for (int j = 0; j < N; j++) {
      sum = x[j] * a + y[j] * b + z[j] * c;
      arr.push_back(sum);
    }

    sort(arr.rbegin(), arr.rend());

    long long tmp = 0;
    for (int i = 0; i < M; i++) {
      tmp += arr[i];
    }
    ans = max(ans, tmp);
  }

  cout << ans << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> x(N);
  std::vector<long long> y(N);
  std::vector<long long> z(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &x[i]);
    scanf("%lld", &y[i]);
    scanf("%lld", &z[i]);
  }
  solve(N, M, std::move(x), std::move(y), std::move(z));
  return 0;
}
