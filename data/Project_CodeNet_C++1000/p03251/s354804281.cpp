#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> xv(n);
  vector<int> yv(m);
  rep(i, n) cin >> xv[i];
  rep(i, m) cin >> yv[i];
  xv.push_back(x);
  yv.push_back(y);
  int xmax = *max_element(xv.begin(), xv.end());
  int ymin = *min_element(yv.begin(), yv.end());
  if(xmax < ymin) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}
    