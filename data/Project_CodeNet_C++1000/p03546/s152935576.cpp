#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int H, W;
int c[10][10];
int A[200][200];

int main() {
  cin >> H >> W;
  rep(i, 10) {
    rep(j, 10) {
      cin >> c[i][j];
    }
  }
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
    }
  }

  rep(k, 10) {
    rep(i, 10) {
      rep(j, 10) {
        c[i][j] = min(c[i][k] + c[k][j], c[i][j]);
      }
    }
  }

  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      if(A[i][j] == -1) continue;
      ans += c[A[i][j]][1];
    }
  }
  cout << ans << endl;
  return 0;
}