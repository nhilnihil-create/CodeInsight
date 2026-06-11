#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
  fastIO;
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> B(m);
  rep(i, m) cin >> B.at(i);

  int cnt = 0;
  rep(i, n) {
    int subsum = 0;
    rep(j, m) {
      int a;
      cin >> a;
      subsum += a * B.at(j);
    }
    if(subsum + c > 0)
      cnt++;
  }

  cout << cnt << endl;
}
