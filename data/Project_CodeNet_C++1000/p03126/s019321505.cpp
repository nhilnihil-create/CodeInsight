#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int like[30][30];

int main() {
  int N, M; cin >> N >> M;
  rep(i,N) {
    int k; cin >> k;
    rep(j,k) {
      int a; cin >> a;
      --a;
      like[i][a] = true;
    }
  }
  int ans = 0;
  rep(j,M) {
    bool alllike = true;
    rep(i,N) {
      if (!like[i][j]) alllike = false;
    }
    if (alllike) ++ans;
  }
  cout << ans << endl;
  return 0;
}