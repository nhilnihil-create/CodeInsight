#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> c(3);
  copy_n(istream_iterator<string>(cin), c.size(), c.begin());
  for (size_t i = 0; i < c.size(); ++i) {
    cout << c[i][i];
  }
  cout << endl;
  return 0;
}
