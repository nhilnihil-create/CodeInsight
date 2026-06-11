#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int h, w;
  cin >> h >> w;
  int c[10][10];
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      cin >> c[i][j];
    }
  }
  for(int k = 0; k < 10; k++) {
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      int a;
      cin >> a;
      if(a != -1) {
        ans += c[a][1];
      }
    }
  }
  cout << ans << endl;
  return 0;
}