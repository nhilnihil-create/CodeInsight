#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int val(char c) {
  return (c == '#');
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h + 2);
  for (int i = 1; i <= h; i++) {
    cin >> s[i];
    s[i] = "." + s[i] + ".";
  }
  for (int j = 1; j <= w; j++) {
    s[0    ] += '.';
    s[h + 1] += '.';
  }
  for (int i = 1; i <= h; i++)
  for (int j = 1; j <= w; j++) {
    if (s[i][j] == '#') continue;
    char c = '0';
    for (int k = -1; k <= 1; k++)
    for (int l = -1; l <= 1; l++) {
      if (k == 0 && l == 0) continue;
      c += val(s[i + k][j + l]);
    }
    s[i][j] = c;
  }
  for (int i = 1; i <= h; i++)
  for (int j = 1; j <= w; j++) {
    cout << s[i][j];
    if (j == w) cout << '\n';
  }
}
