#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = int64_t;
using ul = uint64_t;
using namespace std;

// auto trace = [&](auto V) {
//   for (const auto v : V) {
//     cout << v.first << " " << v.second << endl;
//   }
// };

void solve() {
  int n;
  cin >> n;

  map<int, int> D;
  rep(i, n) {
    int diff;
    cin >> diff;
    if (D.find(diff) != D.end()) {
      D[diff]++;
    } else {
      D[diff] = 1;
    }
  }

  int m;
  cin >> m;

  map<int, int> T;
  rep(i, m) {
    int diff;
    cin >> diff;
    if (T.find(diff) != T.end()) {
      T[diff]++;
    } else {
      T[diff] = 1;
    }
  }

  if (n < m) {
    cout << "NO";
    return;
  }

  for (const auto t : T) {
    if (D.find(t.first) != D.end()) {
      if (D[t.first] < t.second) {
        cout << "NO";
        return;
      }
    } else {
      cout << "NO";
      return;
    }
  }

  cout << "YES";
  return;
}

void wrapper() {
  rep(i, 4) {
    cout << "[TEST " << (i + 1) << "]\n";
    solve();
    cout << "\n";
  }
}

int main() {
  fastIO;
  // wrapper();
  solve();
}
