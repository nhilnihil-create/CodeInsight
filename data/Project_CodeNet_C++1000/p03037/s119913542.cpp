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
  int n, m;
  cin >> n >> m;
  vector<int> gl(m), gr(m);
  rep(i,m) cin >> gl[i] >> gr[i];
  int l = 0;
  int r = INF;
  rep(i,m) {
    l = max(l, gl[i]);
    r = min(r, gr[i]);
  }
  cout << max(0, r-l+1) << endl;
}

int main() {
  solve();
  return 0;
}