#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 303;

int n;
string s;
int k;
int d[M][M][M];

void read() {
  cin >> s >> k;
  n = s.length();
}

void uax(int &x, int y) {
  x = max(x, y);
}

void kill() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int t = 0; t <= k; ++t) {
        int cur = d[i][j][t];
        if (s[i] == s[n - 1 - j])
          uax(d[i + 1][j + 1][t], cur + 1);
        else
          uax(d[i + 1][j + 1][t + 1], cur + 1);
        uax(d[i + 1][j][t], cur);
        uax(d[i][j + 1][t], cur);
      }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; i + j < n; ++j)
      for (int t = 0; t <= k; ++t)
        uax(ans, 2 * d[i][j][t] + 1);

  for (int i = 0; i < n; ++i)
    for (int j = 0; i + j <= n; ++j)
      for (int t = 0; t <= k; ++t)
        uax(ans, 2 * d[i][j][t]);

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}

