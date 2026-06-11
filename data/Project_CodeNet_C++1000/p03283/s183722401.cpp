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
 
int n, m, q;
int sum[501][501];
 
int main() {
  cin >> n >> m >> q;
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    sum[l][r] += 1;
  }
 
  rep(i, n) {
    rep(j, n) {
      sum[i+1][j+1] += sum[i+1][j];
    }
  }
 
  /**
  rep(i, n+1) {
     rep(j, n+1) {
       cout << sum[i][j] << " ";
     }
     cout << endl;
  }
  **/
 
  int ans[100000] = {0};
 
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    for(int j = l; j <= r; j++) {
      ans[i] += sum[j][r];
    }
  }
 
  rep(i, q) {
  	cout << ans[i] << endl;
  }

  return 0;
}