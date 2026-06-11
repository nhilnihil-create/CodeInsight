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

int maxtime(int x) { return (x + 9) / 10 * 10; }

int remtime(int x) { return maxtime(x) - x; }

int main() {
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  int ans = maxtime(A) + maxtime(B) + maxtime(C) + maxtime(D) + maxtime(E);
  ans -= max({remtime(A), remtime(B), remtime(C), remtime(D), remtime(E)});
  cout << ans << endl;
  return 0;
}
