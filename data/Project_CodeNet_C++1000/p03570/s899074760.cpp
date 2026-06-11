#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for ( int i = 0; i < (n); i++ )

int bit[1<<26];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  string s;
  cin >> s;

  int N = s.size();

  const int INF = 1e9;
  fill_n(bit, 1<<26, INF);
  bit[0] = 0;
  int now = 0;
  for ( int i = 0; i < N; i++ ) {
    now ^= (1<<(s[i]-'a'));
    for ( int j = 0; j < 26; j++ ) {
      int b = now ^ (1<<j);
      bit[now] = min(bit[now], bit[b]+1);
    }
  }

  cout << max(1, bit[now]) << endl;

  return 0;
}
