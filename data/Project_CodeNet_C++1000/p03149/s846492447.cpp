#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  map<int, int> count = {{1, 0}, {9, 0}, {7, 0}, {4, 0}};
  int n;
  REP(i, 4) {
    cin >> n;
    if (count.find(n) == count.end()) {
      cout << "NO" << endl;
      return 0;
    }
    ++count.at(n);
  }

  for (auto const &it : count) {
    if (it.second != 1) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}
