#include <bits/stdc++.h>

using namespace std;

typedef __int128 LL;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n;
  long long D;
  cin >> n >> D;
  LL X = D;
  vector<LL> a(n + 1);
  vector<LL> b(n + 2);
  for (LL i = 1; i < b.size(); i++) {
    b[i] = i * i;
  }
  LL sum = 0;
  for (int i = 0; i < n; i++) {
    long long v;
    cin >> v;
    sum += v * 5;
    a[i + 1] = a[i] + v;
  }
  LL ans = sum + X * n;
  for (int i = 1; i <= n; i++) {
    LL now = sum;
    for (int j = n - i, k = 2; j > 0; j -= i, k++) {
      now += (a[j] - a[max(j - i, 0)]) * (b[k + 1] - b[k] - 5);
    }
    ans = min(ans, now + X * i);
  }
  cout << (long long)(ans + n * X) << endl;
  return 0;
}
