#include <iterator>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
int main(int argc, char **argv) {

  vector<int> m;

  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int a;
    cin >> a;
    if (a % 10 == 0) {
      ans += a;
    } else {
      m.push_back(a);
    }
  }
  sort(m.begin(), m.end(), [](int l, int r) {
                             auto lhs = (l/10 + 1) * 10 - l;
                             auto rhs = (r/10 + 1) * 10 - r;
                             return lhs < rhs;
                           });

  if (m.size() == 1) {
    ans += m.back();
  } else if (m.size()) {
    for (int i = 0; i < m.size() - 1; ++i)
      ans += ((m[i] / 10) + 1) * 10;

    ans += m.back();
  }

  cout << ans << endl;

  return 0;
}