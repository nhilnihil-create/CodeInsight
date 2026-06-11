#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vi t(N+1), x(N+1), y(N+1);
  t[0]=0;
  x[0]=0;
  y[0]=0;
  rep(i, N) cin >> t[i+1] >> x[i+1] >> y[i+1];

  rep(i, N) {
    if (t[i+1] - t[i] < abs(x[i+1] - x[i]) + abs(y[i+1] - y[i])) {
      cout << "No" << endl;
      return 0;
    }

    if ((t[i] + x[i] + y[i]) % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
