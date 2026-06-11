#include <bits/stdc++.h>
using namespace std;

pair<long, long> bestsplit(vector<long> &asum, int begin, int end) {
  int lower_bound = begin + 1, upper_bound = end - 1;
  while (upper_bound - lower_bound > 1) {
    int mid = (lower_bound + upper_bound) / 2;
    if (2 * asum.at(mid) < asum.at(begin) + asum.at(end)) {
      lower_bound = mid;
    } else {
      upper_bound = mid;
    }
  }
  if (upper_bound - lower_bound == 1
      && asum.at(begin) + asum.at(end) > asum.at(lower_bound) + asum.at(upper_bound)) {
    lower_bound = upper_bound;
  }
  return make_pair(asum.at(lower_bound) - asum.at(begin),
                   asum.at(end) - asum.at(lower_bound));
}

int main()
{
  int n;
  cin >> n;
  vector<long> asum(n + 1);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    asum.at(i + 1) = asum.at(i) + a;
  }
  long diff_min = 1l << 60;
  for (int i = 2; i <= n - 2; i++) {
    vector<long> s(4);
    pair<long, long> cache;
    cache = bestsplit(asum, 0, i);
    s.at(0) = cache.first;
    s.at(1) = cache.second;
    cache = bestsplit(asum, i, n);
    s.at(2) = cache.first;
    s.at(3) = cache.second;
    long diff = *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end());
    if (diff < diff_min) diff_min = diff;
  }
  cout << diff_min << endl;
}
