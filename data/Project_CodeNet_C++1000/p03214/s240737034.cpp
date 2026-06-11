#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, t{};
  cin >> N;
  vector<int> a(N);
  for (auto &e : a) {
    cin >> e;
    t += e;
    e *= N;
  }
  cout << min_element(begin(a), end(a),
                      [&](int x, int y) { return abs(t - x) < abs(t - y); }) -
              begin(a)
       << endl;

  return 0;
}
