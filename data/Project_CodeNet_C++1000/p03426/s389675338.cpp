#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
using Pii = pair<int, int>;

int cost(Pii a, Pii b) {
  return abs(a.first-b.first) + abs(a.second-b.second);
}

signed main() {
  int H, W, D;
  cin >> H >> W >> D;

  int A[H][W];
  Pii P[H*W+1];
  vector<int> cum(H*W+1, 0);
  REP(i, H) REP(j, W) {
    cin >> A[i][j];
    P[A[i][j]] = Pii(i, j);
  }

  for ( int i = D+1; i <= H*W; i++ ) {
    cum[i] = cum[i-D] + cost(P[i], P[i-D]);
  }

  int Q;
  cin >> Q;
  while ( Q-- ) {
    int l, r;
    cin >> l >> r;
    cout << cum[r] - cum[l] << endl;
  }
  
  return 0;
}
