#include <bits/stdc++.h>
using namespace std;

const long long N = 1e15;

int s(long long x) {
  int ans = 0;
  while (x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

long long get(long long x) {
  vector<int> d;
  {
    long long tmp = x;
    while (tmp > 0) {
      d.push_back(tmp % 10);
      tmp /= 10;
    }
  }
  long long mt = 1, ans = x;
  double mn = x / (double) s(x);
  for (int i = 0; i < (int) d.size(); ++i, mt *= 10) {
    for (int j = d[i]; j <= 9; ++j) {
      long long cur = x + (j - d[i]) * mt;
      if (cur / (double) s(cur) < mn) {
        ans = cur;
        mn = cur / (double) s(cur);
      }
    }
    x -= d[i] * mt;
    x += 9 * mt;
  }
  return ans;
}

int main() {
  long long n = 1;
  vector<long long> snukes;
  while (n < N) {
    snukes.push_back(n);
    n = get(n + 1);
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i)
    printf("%lld\n", snukes[i]);
  return 0;
}