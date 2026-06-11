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

int n = 3;
vector<int> a(3, INF);
vector<int> b(3, INF);

void solve() {
  vector<vector<int>> v(3, vector<int>(3));
  rep(i,n) rep(j,n) cin >> v[i][j];
  rep(i,n) rep(j,n) {
    if (a[i] == INF && b[j] == INF) {
      a[i] = 0;
      b[j] = v[i][j];
    } else {
      if (b[j] == INF) {
        b[j] = v[i][j] - a[i];
      } else if (a[i] == INF) {
        a[i] = v[i][j] - b[j];
      } else {
        if (a[i] + b[j] == v[i][j]) continue;
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