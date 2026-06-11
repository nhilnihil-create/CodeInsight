#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

int c[10][10];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void MAIN() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i <= 9; i++)
  for (int j = 0; j <= 9; j++) {
    cin >> c[i][j];
  }
  for (int k = 0; k <= 9; k++)
  for (int i = 0; i <= 9; i++)
  for (int j = 0; j <= 9; j++) {
    chmin(c[i][j], c[i][k] + c[k][j]);
  }
  int ans = 0;
  for (int i = 1; i <= h; i++)
  for (int j = 1; j <= w; j++) {
    int t; cin >> t;
    if (t != -1) ans += c[t][1];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
