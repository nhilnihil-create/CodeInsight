#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int x[5];
  vector<int> y;
  int s = 0;
  cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
  for (int i = 0; i < 5; ++i) {
    s += (x[i] / 10) * 10;
    if (x[i] % 10 != 0) {
      y.push_back(x[i] % 10);
    }
  }

  if (y.size() == 0) {
    cout << s << endl;
  } else {
    sort(begin(y), end(y));
    cout << s + (y.size() - 1) * 10 + y.front() << endl;
  }
}
