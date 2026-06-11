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
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> v(m);
  rep(i,m) cin >> v[i];
  int l = 0;
  int r = 0;
  rep(i,m) {
    if (v[i] < x) l++;
    else r++;
  }
  cout << min(l,r) << endl;
}

int main() {
  solve();
  return 0;
}