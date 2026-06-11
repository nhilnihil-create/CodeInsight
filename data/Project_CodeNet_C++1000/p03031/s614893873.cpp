#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
using vec = vector<int>;
using P = pair<int,int>;
const int INF = 1e9+7;

int main() {
  int n, m; cin >> n >> m;
  vec s(m, 0), p(m);
  rep(i,m) {
    int k; cin >> k;
    rep(j, k) {
      int t; cin >> t; t--;
      s[i] += 1<<t;
    }
  }
  rep(i,m) {
    cin >> p[i];
  }

  int cnt = 0;
  for (int bit = 0; bit < (1<<n); bit++) {
    bool f = true;
    rep(i,m) {
      if ((__builtin_popcount(bit&s[i])&1) != p[i]) f = false;
    }
    if (f) cnt++;
  }
  cout << cnt << endl;
}
