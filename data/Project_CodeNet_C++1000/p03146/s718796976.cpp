#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int f(int n) {
  if (n % 2 == 0) return n / 2;
  return 3 * n + 1;
}

int main() {
  int s;
  cin >> s;
  vector<int> v(1000000, 0);
  int ans = 1;
  while (true) {
    // 4, 2, 1, 4, 2, 1 ... に収束していく
    if (v[s] > 0) {
      cout << ans << endl;
      return 0;
    }
    v[s]++;
    s = f(s);
    ans++;
  }
  return 0;
}
