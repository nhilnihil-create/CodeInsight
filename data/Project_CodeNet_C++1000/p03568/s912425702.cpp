#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = int64_t;
using ul = uint64_t;
using namespace std;

void solve() {
  int n;
  cin >> n;

  int sum = 1;
  int odd = 1;
  rep(_, n) {
    int n;
    cin >> n;
    if (n % 2 == 0)
      odd *= 2;
    else
      odd *= 1;
    sum *= 3;
  }
  cout << sum - odd << endl;
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
