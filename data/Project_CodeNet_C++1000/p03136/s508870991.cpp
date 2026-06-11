#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  sort(vec.begin(), vec.end());
  int a = accumulate(vec.begin(), vec.end(), -*vec.rbegin());
  int b = *vec.rbegin();
  cout << (b < a ? "Yes" : "No") << endl;
}