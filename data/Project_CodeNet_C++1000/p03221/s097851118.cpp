#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main() {
  fast_io

  int n, m;
  cin >> n >> m;
  vector<int> p(m), y(m);
  vector<vector<int>> yd(n);
  rep(i, m) {
    cin >> p[i] >> y[i];
    p[i]--;
    yd[p[i]].push_back(y[i]);
  }
  rep(i, n) sort(yd[i].begin(), yd[i].end());
  rep(i, m) {
    vector<int> pp = yd[p[i]];
    int num = lower_bound(pp.begin(), pp.end(), y[i]) - pp.begin();
    printf("%06d%06d\n", p[i] + 1, num + 1);
  }
  return 0;
}
