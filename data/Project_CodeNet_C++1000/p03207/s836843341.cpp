#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end());
  *vec.rbegin() /= 2;
  cout << accumulate(vec.begin(), vec.end(), 0) << endl;
}