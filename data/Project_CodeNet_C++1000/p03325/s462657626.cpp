#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int func(int x) {
  if (x % 2 != 0) return 0;
  return func(x / 2) + 1;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += func(a);
  }
  cout << ans << endl;

  return 0;
}