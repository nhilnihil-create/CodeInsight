#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W,N;
  cin >> H >> W >> N;
  int r,c;
  cin >> r >> c;
  r--;
  c--;
  string S,T;
  cin >> S >> T;
  int DP[(2*N)+1][4];
  // L : 0,R : 1,U : 2,D : 3
  DP[0][0] = c;
  DP[0][1] = c;
  DP[0][2] = r;
  DP[0][3] = r;
  bool can = true;
  for (int i = 0; i < (2*N); i++) {
    DP[i+1][0] = DP[i][0];
    DP[i+1][1] = DP[i][1];
    DP[i+1][2] = DP[i][2];
    DP[i+1][3] = DP[i][3];
    if (i % 2 == 0) {
      if (S[i/2] == 'L') {
        DP[i+1][0]--;
      } else if (S[i/2] == 'R') {
        DP[i+1][1]++;
      } else if (S[i/2] == 'U') {
        DP[i+1][2]--;
      } else {
        DP[i+1][3]++;
      }
    } else {
      if (T[i/2] == 'L') {
        DP[i+1][1]--;
        DP[i+1][1] = max(0,DP[i+1][1]);
      } else if (T[i/2] == 'R') {
        DP[i+1][0]++;
        DP[i+1][0] = min(W-1,DP[i+1][0]);
      } else if (T[i/2] == 'U') {
        DP[i+1][3]--;
        DP[i+1][3] = max(0,DP[i+1][3]);
      } else {
        DP[i+1][2]++;
        DP[i+1][2] = min(H-1,DP[i+1][2]);
      }
    }

    for (int j = 0; j < 2; j++) {
      if (0 <= DP[i+1][j] && DP[i+1][j] < W) {
        
      } else {
        can = false;
      }
    }
    for (int j = 2; j < 4; j++) {
      if (0 <= DP[i+1][j] && DP[i+1][j] < H) {
        
      } else {
        can = false;
      }
    }
  }

  if (can) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}