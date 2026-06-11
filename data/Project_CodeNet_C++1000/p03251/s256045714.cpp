#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(){
  int n, m, X, Y; cin >> n >> m >> X >> Y;
  vector<int> x(n), y(m);
  for(int i = 0; i < n; i++) cin >> x[i];
  for(int i = 0; i < m; i++) cin >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int maxx = max(X, x[x.size() - 1]);
  int miny = min(Y, y[0]);
  if(miny - maxx > 0) cout << "No War\n";
  else cout << "War\n";
  return;
}

int main(){
  solve();
  return 0;
}
