#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> vec(n + 1);
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    vec[a] = 1;
  }
  partial_sum(vec.begin(), vec.end(), vec.begin());
  cout << min(vec[x], vec[n] - vec[x]) << endl;
}
