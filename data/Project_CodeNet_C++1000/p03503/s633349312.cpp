#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n;

  vector<vector<int> > f(n, vector<int>(10));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) cin >> f[i][j];
  }

  vector<vector<int> > p(n, vector<int>(11));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 11; j++) cin >> p[i][j];
  }

  int ans = -2000000000;
  for (int i = 1; i < (1 << 10); i++) {
    int tmp = 0;
    bitset<10> x(i);
    for (int j = 0; j < n; j++) {
      bitset<10> fb(0);
      for (int k = 0; k < 10; k++) {
        if (f[j][k]) fb.set(k);
      }
      fb &= x;
      tmp += p[j][fb.count()];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
