#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

int n, a[100005], ans;
map<int, int> memo;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]]++;
  }

  for (auto i = memo.begin(); i != memo.end(); i++) {
    int f = (*i).first;
    int s = (*i).second;
    if (f < s) {
      ans += s - f;
    }
    if (f > s) {
      ans += s;
    }
  }

  cout << ans << endl;
}