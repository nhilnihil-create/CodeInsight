#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n), where(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    where[p[i]] = i;
  }

  int right = -1;
  int left = 0;
  int result = 0;
  while (left < n) {
    left = right + 1;
    right = left;
    while (right + 1 < n && where[right] < where[right + 1]) {
      right++;
    }
    result = max(result, right - left + 1);
  }

  cout << n - result << endl;

  return 0;
}
