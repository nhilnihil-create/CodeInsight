#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> as(n);
  vector<int> bs(n);
  int t;
  long long sum = 0;
  long long minus = 0;
  int count = 0;
  for (int &a : as) cin >> a;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    bs[i] = as[i] - t;
    sum += bs[i];
    if (bs[i] < 0) {
      minus -= bs[i];
      ++count;
    }
  }

  if (sum < 0) {
    cout << -1 << endl;
    return 0;
  }

  sort(bs.begin(), bs.end());

  int c = n;
  while (minus > 0) {
    --c;
    minus -= bs[c];
    ++count;
  }

  cout << count << endl;
  return 0;
}