#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  int N, K;
  cin >> N >> K;

  vector<long long> x(N);
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> x[i];
    a[i] = abs(x[i]);
  }

  long long ret = 1000000000000;
  // right to left
  vector<long long>::iterator iter = lower_bound(x.begin(), x.end(), 1);
  int start = distance(x.begin(), iter);
  for (int i = start; i < N; ++i) {
    if (i + 1 - start == K)
      ret = min(ret, x[i]);
    else if (i + 1 >= K)
      ret = min(ret, 2 * x[i] + abs(x[start - (K - (i - start)) + 1]));
  }
  // left to right
  for (int i = start - 1; i >= 0; --i) {
    if (start - i == K)
      ret = min(ret, -x[i]);
    else if (N - i >= K)
      ret = min(ret, -2 * x[i] + x[start + (K - (start - i)) - 1]);
  }

  cout << ret << endl;

  return 0;
}