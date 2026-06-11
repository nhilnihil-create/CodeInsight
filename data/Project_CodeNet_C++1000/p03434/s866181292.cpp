#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end(), greater<int>());

  int sa = 0;
  int sb = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0)
      sa += vec[i];
    else
      sb += vec[i];
  }

  cout << sa - sb << endl;
}
