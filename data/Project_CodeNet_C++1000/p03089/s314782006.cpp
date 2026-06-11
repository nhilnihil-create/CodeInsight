#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> result;

  for (int step = 0; step < n; ++step) {
    int i = n - 1 - step;
    while (i >= 0 && a[i] != i) i--;
    if (i == -1) {
      cout << -1 << endl;
      return 0;
    }

    result.push_back(a[i] + 1);
    a.erase(a.begin() + i);
  }

  reverse(result.begin(), result.end());

  for (int i = 0; i < n; ++i) {
    cout << result[i] << endl;
  }
  cout << endl;

  return 0;
}
