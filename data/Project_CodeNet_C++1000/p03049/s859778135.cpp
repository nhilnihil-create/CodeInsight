#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) {
    cin >> s.at(i);
  }
  int ab = 0;
  int firstB = 0;
  int lastA = 0;
  int bothAb = 0;
  for (string ss : s) {
    bool f = (ss.front() == 'B');
    bool l = (ss.back() == 'A');
    if (f) {
      firstB++;
    }
    if (l) {
      lastA++;
    }
    if (f && l) {
      bothAb++;
    }
    for (int i = 0; i < ss.size() - 1; i++) {
      if (ss.substr(i, 2) == "AB") {
        ab++;
      }
    }
  }

  int edge = min(firstB, lastA);
  if (firstB > 0 && firstB == lastA && firstB == bothAb) {
    edge--;
  }
  int res = ab + edge;
  cout << res << endl;
  return 0;
}
