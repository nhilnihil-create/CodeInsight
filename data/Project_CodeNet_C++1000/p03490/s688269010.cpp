#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

bool dp[2][N+N], tmp[N+N];

void modify(int dir, int cnt) {
  memset( tmp, 0, sizeof(tmp));
  for (int i = 0; i < N+N; i++) {
    if ( dp[dir][i] ) {
      tmp[i-cnt] = 1;
      tmp[i+cnt] = 1;
    }
  }
  for (int i = 0; i < N+N; i++) dp[dir][i] = tmp[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int x, y;
  cin >> s >> x >> y;
  s += 'T';
  int n = s.length(), dir = 0; // x-axis
  dp[0][N] = dp[1][N] = 1;
  bool start = 1;
  for ( int i = 0, cnt = 0; i < n; i++) {
    if ( start && s[i] == 'F' ) {
      dp[0][N+i+1] = 1;
      dp[0][N+i] = 0;
      continue;
    }
    else start = 0;
    if ( s[i] == 'T' ) {
      modify( dir, cnt );
      cnt = 0;
      dir ^= 1;
    }
    else {
      cnt++;
    }
  }
  if ( dp[0][N+x] && dp[1][N+y] ) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
