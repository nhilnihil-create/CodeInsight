#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve() {
  int A, B, C, D;
  string s; cin >> s;
  A = s[0]-'0';
  B = s[1]-'0';
  C = s[2]-'0';
  D = s[3]-'0';

  for (char a: {'+', '-'}) {
    int AA = a == '+' ? A + B : A - B;
    for (char b: {'+', '-'}) {
      int BB = b == '+' ? AA + C : AA - C;
      for (char c: {'+', '-'}) {
        int CC = c == '+' ? BB + D : BB - D;
        if (CC == 7) {
          printf("%d%c%d%c%d%c%d=7\n", A, a, B, b, C, c, D);
          return;
        }
      }
    }
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
