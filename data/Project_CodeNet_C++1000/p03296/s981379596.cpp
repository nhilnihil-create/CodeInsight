#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int n; cin >> n;
  vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  int cur = 1;
  int result = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == n || a[i] != a[i - 1]) {
      result += cur / 2;
      cur = 1;
    } else {
      cur++;
    }
  }
  cout << result << endl;
  return 0;
}
