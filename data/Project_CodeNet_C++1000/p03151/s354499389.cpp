#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  long long a[N];
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  long long b[N];
  for (int i = 0; i < N; ++i)
    cin >> b[i];

  long long diff_total = 0;
  vector<long long> diff(N);
  bool changed[N];
  for (int i = 0; i < N; ++i) {
    diff_total += a[i] - b[i];
    diff[i] = a[i] - b[i];
    changed[i] = false;
  }

  if (diff_total < 0) {
    cout << -1 << endl;
    return 0;
  }

  sort(diff.begin(), diff.end());

  int last_provider = N - 1;
  int cursor = 0;
  while (true) {
    if (diff[cursor] >= 0)
      break;
    if (abs(diff[last_provider]) > abs(diff[cursor])) {
      diff[last_provider] += diff[cursor];
      diff[cursor] = 0;
      changed[cursor] = true;
      changed[last_provider] = true;
      ++cursor;
    } else {
      diff[cursor] += diff[last_provider];
      diff[last_provider] = 0;
      changed[cursor] = true;
      changed[last_provider] = true;
      if (diff[cursor] == 0)
        ++cursor;
      --last_provider;
    }
  }

  int ret = 0;
  for (int i = 0; i < N; ++i)
    if (changed[i])
      ++ret;

  cout << ret << endl;

  return 0;
}