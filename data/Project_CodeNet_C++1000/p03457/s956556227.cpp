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
  int n;
  cin >> n;
  vector<int> t(n+1), x(n+1), y(n+1);
  rep(i,n) cin >> t[i+1] >> x[i+1] >> y[i+1]; 
  rep(i,n) {
    int dt = t[i+1] - t[i];
    int dx = x[i+1] - x[i];
    int dy = y[i+1] - y[i];
    int dis = abs(dx) + abs(dy);
    if (dt < dis || (dt % 2 != dis % 2)) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  solve();
  return 0;
}