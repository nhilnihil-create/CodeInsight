#include <bits/stdc++.h>
using namespace std;
#define rep(i, ss, ee) for (int i = (ss); i <= (ee); ++i)

void solve() {
  int N;
  cin >> N;
  rep(a, 0, 25) {
    rep(b, 0, 14) {
      if (a * 4 + b * 7 == N) {
        cout << "Yes" << endl;
        // cout << a << " " << b << endl;
        return;
      };
    }
  }
  cout << "No" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}