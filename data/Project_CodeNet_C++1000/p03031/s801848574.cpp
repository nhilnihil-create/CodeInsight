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

int s[10][10];

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> k(M);
  vector<int> p(M);
  rep(i,M) {
    cin >> k[i];
    rep(j,k[i]) cin >> s[i][j];
  }
  rep(i,M) cin >> p[i];

  vector<int> sw(N);

  int ans = 0;
  rep(i,1<<N) {
    bool ok = true;
    rep(j,N) {
      if (i>>j&1) sw[j] = 1;
      else sw[j] = 0;
    }
    rep(j,M) {
      int ons = 0;
      rep(l,k[j]) if (sw[s[j][l]-1] == 1) ons++;
      if (ons%2!=p[j]) ok = false;
    }
    if (ok) ++ans;
  }
  cout << ans << endl;
  return 0;
}