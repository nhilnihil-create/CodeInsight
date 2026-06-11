#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i,h) cin >> v[i];
  rep(i,h) {
    rep(j, w) {
      if (v[i][j] == '.') continue;
      bool b = true;
      rep(k, 4) {
        int y = dy[k] + i;
        int x = dx[k] + j;
        if (y < 0 || h - 1 < y || x < 0 || w - 1 < x) continue;
        if (v[y][x] == '#') b = false;
      }
      if (b) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}

int main() {
  solve();
  return 0;
}