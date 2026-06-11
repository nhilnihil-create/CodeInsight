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
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  vector<int> copy = v;
  sort(ALL(copy));
  int l = copy[n / 2 - 1];
  int r = copy[n/ 2];
  if (l == r) {
    rep(i,n) cout << l << " ";
    cout << endl;
    return;
  }
  rep(i,n) {
    if (v[i] < r) cout << r << " ";
    else cout << l << " ";
  }
  cout << endl;
}

int main() {
  solve();
  return 0;
}