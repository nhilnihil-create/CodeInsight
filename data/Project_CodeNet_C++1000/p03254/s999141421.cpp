#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = int64_t;
using ul = uint64_t;
using namespace std;

void solve() {
  int n;
  ul x;
  cin >> n >> x;

  vector<ul> A(n);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());

  // Tabun Greedy To iu Namae No
  // Algorithm To iuka Kangae Kata
  // Dato Omouno dakedo na ...
  int cnt = 0;
  for (size_t i = 0; i < A.size() - 1; ++i) {
    if (x >= A.at(i)) {
      cnt++;
      x -= A.at(i);
    } else if (x == A.at(i)) {
      cout << cnt + 1 << endl;
      return;
    } else {
      cout << cnt << endl;
      return;
    }
  }

  if (x == A.back())
    cnt++;
  cout << cnt << endl;
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
