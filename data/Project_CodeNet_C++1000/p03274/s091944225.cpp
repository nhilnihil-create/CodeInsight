#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  copy_n(istream_iterator<int>(cin), N, x.begin());

  int result = 2 * (x[N - 1] - x[0]);
  for (int i = 0; i < N - K + 1; ++i) {
    int tmp = 0;
    if (0 <= x[i]) tmp = x[i + K - 1];
    else if (x[i + K - 1] <= 0) tmp = -x[i];
    else if (abs(x[i]) <= x[i + K - 1]) tmp = x[i + K - 1] - 2 * x[i];
    else tmp = 2 * x[i + K - 1] - x[i];

    if (tmp < result) result = tmp;
  }

  cout << result << endl;
  return 0;
}
